var dgram = require('dgram');
var crypto = require('crypto');
var logger = require('winston');
var Promise = require('bluebird');
var request = Promise.promisify(require('request'), {multiArgs: true});
var bencode = require('bencode');
var Peer = require('../Peer/peer.js');

Promise.promisifyAll(request, {multiArgs: true});

module.exports = function(Bittorrent) {
	Bittorrent.prototype.reqHttpTracker = function(trackerIndex)
	{
		var tracker = this.httpTracker[trackerIndex];
		var downloaded = 0;
		var event = 'started';
		var left = this.metadata.length;

		if (tracker.firstCall == false) {
			downloaded = this.downloadedBytes;
			left = this.metadata.length - this.downloadedBytes;
			event = '';
			if (left == 0)
				event = 'completed';
		}

		// optionals arguments: compact, no_peer_id, numwant
		tracker.urlParam = {
			info_hash: this.encodeValue(this.metadata.infoHash),
			peer_id: this.peerId,
			port: 6885,
			uploaded: '0',
			downloaded: downloaded.toString(),
			left: left.toString(),
			event: event,
			compact: '1',
			no_peer_id: '1',
		};

		tracker.queryHref = tracker.url;
		Object.keys(tracker.urlParam).forEach(function(paramName, i) {
			if (i == 0)
				tracker.queryHref += '?' + paramName + '=' + tracker.urlParam[paramName];
			else
				tracker.queryHref += '&' + paramName + '=' + tracker.urlParam[paramName];
		});
		request.getAsync({url: tracker.queryHref, encoding: null})
		.spread((res) => {
			logger.verbose('success request on tracker: ' + res.request.href);
			var trackerData = this.httpTrackerReqData(res);
			if (trackerData == -1)
				return ;
			tracker.interval = trackerData.interval;
			tracker.peers = trackerData.peers;
			this.peerConnection(tracker.peers);
			tracker.firstCall = false;

			// logger.verbose('Tracker: ' + tracker.url + ' will be called every ' +
				// tracker.interval + ' seconds');
			// setTimeout(this.reqHttpTracker, trackerData.interval * 1000)
		}).catch((err) => {
			logger.warn('Something wrong happened in tracker request: ' +
			 tracker.url + ' (' + err + ')');
		});
	},
	Bittorrent.prototype.httpTrackerReqData = function(res) {
		try {
			var bodyBdecoded = bencode.decode(res.body);
		} catch (err) {
			logger.error('Cannot bdecode body of ' + res.request.href + '(', err, ')');
			return (-1);
		}
		var peers = [];
		if (typeof bodyBdecoded.peers == 'undefined') {
			var errorMsg = '[Tracker response failure]: ';
			Object.keys(bodyBdecoded).forEach(function(key) {
				errorMsg += (key + ' : ' + Buffer.from(bodyBdecoded[key]).toString());
			});
			logger.warn(errorMsg + '(' + res.request.href + ')');
			return (-1);
		}

		for (var i = 0; i < Buffer.byteLength(bodyBdecoded.peers) / 6; i++) {
	    	var ip = bodyBdecoded.peers.slice(i * 6, (i + 1) * 6);
	  		var peer = ip.slice(0, 4).join('.') + ":" + ip.readUInt16BE(4);

	  		peers.push(peer);
	    }
	    if (peers.length == 0)
	    	logger.warn('No peers on tracker: ' + res.request.href);
	    var data = {
	    	peers: peers,
	    	interval: bodyBdecoded.interval
	    }
	    logger.debug('Number of peers: ' + data.peers.length);
	    return data;
	},
	Bittorrent.prototype.reqUdpTracker = function(trackerIndex) {
		var socket = dgram.createSocket('udp4');
		var tracker = this.udpTracker[trackerIndex];
		var connection = false;
		var announce = false;
		var socketsAlive = [];
		var socketHost;
		// maybe object with transaction_id + (connection_id)
		// verif on each connection

		var connReqBuffer = Buffer.alloc(16);

		connReqBuffer.writeUIntBE(0x41727101980, 0, 8); // protocol_id - magic constant
		connReqBuffer.writeUInt32BE(0, 8); // action - connect
		connReqBuffer.writeUInt32BE(crypto.randomBytes(4), 12); // transaction_id

		logger.debug('udp: Sending connection message to: ' + tracker.hostname + ':' + tracker.port);

		// need to add retry
		socket.send(connReqBuffer, 0, Buffer.byteLength(connReqBuffer),
			tracker.port, tracker.hostname, function(err) {
			if (err)
				logger.warn('Error on sending request to udp tracker: ' + err);
			else
				connection = true;
		});

		socket.on('listening', () => {
			var socketAddr = socket.address();
			socketHost =  socketAddr.address + ':' + socketAddr.port;

			socketsAlive.push(socketHost);
			logger.debug('socket listening on ' + socketHost);
		});

		socket.on('message', (msg, remote) => {
			var socketAddr = socket.address();
			socketHost =  socketAddr.address + ':' + socketAddr.port;

			var remoteHost = remote.address + ':' + remote.port;
			logger.debug('socket got: ',msg , ' ', Buffer.byteLength(msg),
				' from ' + remote.address + ':' + remote.port);

			if (connection == true) {
				try {
					var connRes = {
						action: msg.readUInt32BE(0),
						transaction_id: msg.slice(4, 8),
						connection_id: msg.slice(8, 16)
					}
				} catch (err) {
					logger.debug('Something went wrong on udp msg response: ' + err);
					socket.close();
					// retry instead of close ?
				}
				if (connRes.action == 3) {
					logger.debug('udp msg connection respond with an error: ' + msg.toString());
					socket.close();
				}
				logger.debug('Connection response: ', connRes);
				var downloaded = Buffer.alloc(8);
				var event = Buffer.from([0, 0, 0, 2]);
				var left = Buffer.alloc(8);

				if (tracker.firstCall == false) {
					downloaded.writeUIntBE(this.downloadedBytes, 0, 8);
					left.writeUIntBE(this.metadata.length - this.downloadedBytes, 0, 8);
					event = Buffer.alloc(4);
					if (this.metadata.length - this.downloadedBytes == 0) // left == 0
						event = Buffer.from([0, 0, 0, 1]);
				}

				var announceReqBuf = Buffer.concat([
					connRes.connection_id, // connection_id 0-8
					Buffer.from([0, 0, 0, 1]), // action (1: announce) 8-12
					connRes.transaction_id, // transaction_id 12-16
					this.metadata.infoHashBuffer, // infoHash 16-36
					Buffer.from(this.peerId), // peerId 36-56
					downloaded, // downloaded 56-64
					left, // left 64-72
					Buffer.alloc(8), // uploaded 72-80
					event, // event 80-84 (0: none; 1: completed; 2: started; 3: stopped)
					Buffer.alloc(4), // ip address 84-88 (0: default)
					Buffer.from(crypto.randomBytes(4)), // 88-92 key
					Buffer.from([0, 0, 0, -1]), // num_want 92-96 (-1: default)
					Buffer.from([0x1a, 0xe5], 'hex'), // 96-98 port
				], 98);

				logger.debug('Announce request: ', announceReqBuf, remoteHost);
				socket.send(announceReqBuf, 0, Buffer.byteLength(announceReqBuf),
					remote.port, remote.address, function(err) {
					if (err)
						logger.warn('Error on sending request to udp tracker: ' + err);
					else {
						connection = false;
						announce = true;
					}
				});
			}
			else if (announce == true) {
				tracker.action = msg.readUInt32BE(0);
				tracker.transaction_id = msg.readUInt32BE(4);
				tracker.interval = msg.readUInt32BE(8);
				tracker.leechers = msg.readUInt32BE(12);
				tracker.seeders = msg.readUInt32BE(16);

				logger.verbose('Udp tracker ' + tracker.hostname + ': ', tracker);
				var peersHostBuf = msg.slice(20, Buffer.byteLength(msg));
				tracker.peers = [];
				for (var i = 0; i < Buffer.byteLength(peersHostBuf) / 6; i++) {
					try {
						var peerHostBuf = peersHostBuf.slice(i * 6, (i + 1) * 6);
		  				var peerHost = peerHostBuf.slice(0, 4).join('.') + ":" + peerHostBuf.readUInt16BE(4);

		  				tracker.peers.push(peerHost);
					} catch (err) {
						logger.debug('Incorrect peerHost (' + err + ')')
					}
				}
				this.peerConnection(tracker.peers);
				// setTimeout(this.reqUdpTracker, tracker.interval * 1000);
				tracker.firstCall = false;

				socket.close();
			}
		});

		socket.on('error', (err) => {
			socketHost =  socketAddr.address + ':' + socketAddr.port;
			logger.debug('socket error: ' + err);
			socket.close();
		});

		socket.on('close', () => {
			socketsAlive.splice(socketsAlive.indexOf(socketHost), 1);
			logger.debug('socket ' + socketHost + ' close');
			if (socketsAlive.length == 0)
				logger.debug('No udp connection with trackers alive');
		});
	},
	Bittorrent.prototype.peerConnection = function(peersHost) {
		peersHost.forEach((peerHost) => {
			if (this.peers.indexOf(peerHost) == -1) {
				this.peers.push(peerHost);
				var peer = new Peer(peerHost, this);
				peer.initConn();
			}
		});
	}
}