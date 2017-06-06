var parseTorrentFile = require('parse-torrent-file'),
    request = require('request'),
    crypto = require('crypto'),
    path = require('path'),
    fs = require('fs');
var Bittorrent = require('../bittorrentProtocol/Bittorrent/bittorrent.js');

var ffmpeg = require('fluent-ffmpeg');
var Converter = require('../models/converter.js');
//var Readable = require('stream').Readable;

var torrent = {};

function sha1(str) {
    return crypto.createHash('sha1').update(str, 'utf8').digest('hex');
}

function sha1File(path, callback) {
    var stream = fs.createReadStream(path),
        hash = crypto.createHash('sha1');
    stream.on('data', function(data) {
        hash.update(data, 'utf8');
    })
    .on('end', function() {
        callback(hash.digest('hex'));
    })
    .on('error', function() {
        callback(hash.digest('hex'));
    });
}

/*
torrent.path = function(key, converted, rel, resolution, fps) {
    var ret = null;

    if (!!converted) {
        ret = torrent.actualdl[key].convertedPath;
        resolution = resolution || 1080;
        fps = fps || 25;
        if (resolution && fps) {
            ret += '/'+torrent.actualdl[key].name+'-'+resolution+'p '+fps+'fps.webm';
            //todo
        }
        else {
            ret += '/'+torrent.actualdl[key].name+'.webm';
        }
    }
    else {
        ret = torrent.actualdl[key].relativePath+'/'+torrent.actualdl[key].name;
    }
    return (!!rel ? ret : (ret ? path.resolve(ret) : null));
}*/

torrent.dwnlds = {};

torrent.isDownloading = function(key) {
    //console.log(key, Object.keys(torrent.dwnlds), !!torrent.dwnlds[key]);
    return !!torrent.dwnlds[key];
}

torrent.getAvailableSettings = function(key, cb) {
    if (this.dwnlds[key].converter) {
        this.dwnlds[key].converter.availableSettings((infos) => {
            //console.log('KEY 0:', key, infos, this.dwnlds[key].converter.nameFile);
            if (infos.success) {
                for (var i = 0; i < infos.choices.length; i++) {
                    var data = this.dwnlds[key].converter.getData(infos.choices[i]);
                    if (data !== null) {
                        infos.choices[i].percent = data.percent;
                        infos.choices[i].secStreamable = data.secStreamable;
                    }
                }
            }
            infos.percent = this.dwnlds[key].converter.percent;
            infos.duration = this.dwnlds[key].converter.duration;
            cb(infos);
        });
    }
    else {
        setTimeout(() => {
            torrent.getAvailableSettings(key, cb);
        }, 500);
    }
}

torrent.getFile = function(key, res, fps, cb) {
    if (this.dwnlds[key].converter) {
        this.dwnlds[key].converter.checkSettings({res, fps}, (settings)=>{
            if (settings) {
                var l = new Date().getTime()+Math.random();
                this.dwnlds[key].converter.addEncoder(settings, (data) => {
                    console.log('mmmmmmmmmmmmmm', l);
                    cb(data);
                });
            }
            else {
                console.log('this settings doesn\'t exist !');
                console.log(settings);
                cb(null);
            }
        });
    }
    else {
        cb({success:false});
    }
}


torrent.startDownload = function(pth, file, cb) {
    var torrentPath = path.resolve(pth),
        key = pth+'#'+file;

    if (!this.isDownloading(key)) {
        this.dwnlds[key] = {};
        this.dwnlds[key].downloader = new Bittorrent(torrentPath, [file]);
        console.log('$$$$$$$$$$$$$$$$$$$$$$$$ new Bittorrent add');
        console.log('file:', file);
        this.dwnlds[key].downloader.init();
        this.dwnlds[key].downloader.started((fileInfos) => {
            console.log('[[[ Start download ]]] - key:', key);

            //this.dwnlds[key].downloader.filesInfo(null, {verbose: false}, (fileInfos) => {
                //this.dwnlds[key].originalFile = filePath;
                this.dwnlds[key].converter = new Converter(fileInfos.path, fileInfos.name, fileInfos.finalLen);

                //console.log('KEY:', key);

                this.dwnlds[key].inter = setInterval(()=>{
                    if (this.dwnlds[key].inter !== null) {
                        //console.log('KEY 2:', key);
                        //console.log('update', this.dwnlds[key].downloader);
                        this.dwnlds[key].downloader.currentLen([file], (currentLen) => {
                            this.dwnlds[key].converter.update(currentLen);
                        });
                    }
                }, 2500);
            //});
        });
        this.dwnlds[key].downloader.finished((fileInfos) => {
            console.log('[[[ Finish download ]]] - key:', key, fileInfos);
            if (this.dwnlds[key].inter) {
                clearInterval(this.dwnlds[key].inter);
                this.dwnlds[key].inter = null;
                console.log('inter is null');
            }
            //this.dwnlds[key].originalFile = filePath;
            if (!this.dwnlds[key].converter) {
                //this.dwnlds[key].downloader.filesInfo(null, {verbose: false}, (fileInfos) => {
                //});
                this.dwnlds[key].converter = new Converter(fileInfos.path, fileInfos.name, fileInfos.finalLen);
                delete this.dwnlds[key].downloader;
                this.dwnlds[key].converter.finished();
            }
            else {
                delete this.dwnlds[key].downloader;
                this.dwnlds[key].converter.finished();
            }
        });
    }
    else {
        //console.log('Key exist', key);
    }
    return key;
}


            //this.dwnlds[key].relativePath = fileInfos.relativePath;
            //this.dwnlds[key].name = fileInfos.name;
            //this.dwnlds[key].streamData = new Readable({read(){}});
            //this.dwnlds[key].lastLen = 0;

            //    this.dwnlds[key].convertedPath = this.dwnlds[key].relativePath.replace('/downloaded', '/converted');
            //    this.dwnlds[key].percent = fileInfos.percent;

                //console.log(fileInfos.percent, fileInfos.firstPieceMissing, fileInfos.currentLen, torrent.actualdl[key].lstLen+1024*1024);
                /*
                //if file not completly download and have dl more than 1mo since last interval
                if ((fileInfos.currentLen < fileInfos.finalLen && fileInfos.currentLen > torrent.actualdl[key].lastLen + (5*1024*1024)) || fileInfos.currentLen == fileInfos.finalLen) {
                    var start = this.dwnlds[key].lastLen;
                    var end = fileInfos.currentLen - 1;

                    var read = fs.createReadStream(this.dwnlds[key].originalFile, {start: start, end: end});
                    //var len = 0;
                    read.on('data', function(buff) {
                    //    len += buff.length;
                        this.dwnlds[key].streamData.push(buff);
                    })
                    .on('end', function() {
                        //console.log('>>> end - added:', len);
                        if (fileInfos.currentLen == fileInfos.finalLen) {
                            console.log('Push END !');
                            this.dwnlds[key].streamData.push(null);
                        }
                        this.dwnlds[key].lastLen = fileInfos.currentLen;
                        //else {
                            //torrent.actualdl[key].converter = setTimeout(tttt, 1000);
                        //}
                    });
                }* /
            });

            //converter.init(this.dwnlds[key].originalFile, ()=>{

            //});
            /*
            var isStreamable = false;
            var tttt = ()=>{
                console.log('tttt');
                console.log('isStreamable fileInfos', isStreamable);
                if (!isStreamable) {
                    //torrent.actualdl[key].downloader.filesInfo(null, {verbose: false}, function(fileInfos) {
                    //    console.log('ppppppppppppppppppp');
                    //    converter.getInfos(this.dwnlds[key].originalFile, (infos)=>{
                    //        console.log('fps:', infos.streams[0].avg_frame_rate);
                    //        var fps = infos.streams[0].avg_frame_rate.split('/');
                    //        fps = Math.round(parseInt(fps[0]) / parseInt(fps[1]));
                    //        torrent.actualdl[key].videoSettings = {width: infos.streams[0].width, height: infos.streams[0].height, fps, duration: infos.format.duration};
                    //        console.log(torrent.actualdl[key].videoSettings, Object.keys(torrent.actualdl[key]));
                            if (infos && infos.format && infos.format.duration) {
                                isStreamable = true;
                                stream.runEncoders(key);
                            }
                            torrent.actualdl[key].converter = setTimeout(tttt, 1000);
                        });
                    //});
                }* /
                else {
                    torrent.actualdl[key].downloader.filesInfo(null, {verbose: false}, function(fileInfos) {


                            //stre.pipe(process.stdout);
                            //var write = fs.createWriteStream(fileInfos.dlPath+'.webm');
                            //read.pipe(write);
                            //console.log(fileInfos.dlPath, {start: start, end: end});

                        }
                        else {
                            torrent.actualdl[key].converter = setTimeout(tttt, 1000);

                        }
                    });
                }
                /*
                var file = fs.createReadStream(fileInfos.dlPath, {start: start, end: end});
                * /
            }
            this.dwnlds[key].converter = setTimeout(tttt, 1000);
        });
        this.dwnlds[key].downloader.finished(function(filePath) {
            console.log('finished: aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa ', filePath, key);
            //torrent.actualdl[key].downloader.filePath = filePath;
            //torrent.fileView(req, );
            //clearInterval(torrent.actualdl[key].converter);

        });
    }
}*/

torrent.download = function(url, callback) {
    var name = './torrent/files/tmp-'+sha1(url+new Date())+'.torrent';
    var write = fs.createWriteStream(name);
    var options = { headers: {'user-agent': 'node.js'} };
    request.get(url, options, function(err, res) {
        write.close();
        callback(name);
    }).pipe(write);
}

torrent.getInfos = function(req, obj, callback) {
    var db = req.app.locals.db;
    var torrentdb = db.collection('torrent');

    torrent.get(req, obj, (object)=>{
        if (object.success && object.doc) {
            var trnt = fs.readFileSync(object.doc.file), parsed;
            try {
                parsed = parseTorrentFile(trnt);
            } catch (err) {
                return callback({success: false, message: 'Error: torrent file was corrupt.', error: err});
            }
            callback({success: true, files: parsed.files});
        }
        else if (object.success && !object.doc) {
            callback({success: false, message: 'Torrent not found.'});
        }
        else {
            callback(object);
        }
    });
}

torrent.get = function(req, obj, callback) {
    var db = req.app.locals.db;
    var torrentdb = db.collection('torrent');

    if (obj.path) {
        sha1File(obj.path, (sha1)=>{
            torrentdb.findOne({hash: sha1}, {}, function(err, doc) {
                if (!err && !doc) {
                    callback({success: true, doc:null, message: 'File not exist.'});
                }
                else if (!err && doc)
                    callback({success: true, doc});
                else
                    callback({success: false, message: 'Error in mongodb request.', error: err});
            });
        });
    }
    else if (obj.hash) {
        torrentdb.findOne({hash: obj.hash}, {}, function(err, doc) {
            if (!err && !doc) {
                callback({success: true, doc:null, message: 'File not exist.'});
            }
            else if (!err && doc)
                callback({success: true, doc});
            else
                callback({success: false, message: 'Error in mongodb request.', error: err});
        });
    }
    else {
        callback({success: false, message: 'Bad input, need path or hash to get torrent.'});
    }
}

torrent.add = function(req, path, callback) {
    var db = req.app.locals.db;
    var torrentdb = db.collection('torrent');

    sha1File(path, (sha1)=>{
        var obj = {
            hash: sha1,
            file: './torrent/files/'+sha1+'.torrent',
            files: []
        }
        var trnt = fs.readFileSync(path), parsed;
        try {
            parsed = parseTorrentFile(trnt);
        } catch (err) {
            return callback({success: false, message: 'Error: torrent file was corrupt.', error: err});
        }
        //console.log(parsed.name)
        torrentdb.insertOne(obj, function(err, r) {
            if (!err) {
                //console.log(err, r);
                fs.renameSync(path, obj.file);
                callback({success: true, hash:obj.hash, message: 'Torrent add.'});
            }
            else
                callback({success: false, message: 'Error in insert.', error: err});
        });
    })
}

torrent.fileView = function(req, hash, pth) {
    var db = req.app.locals.db;
    var torrentdb = db.collection('torrent');

    console.log('============================================= update');
    torrentdb.update({hash, "files.name": pth}, {$set: {"files.$.date" : new Date()}}, function (err, res) {
        console.log('update', err, res.result.nModified);
        if (!err && res && res.result && res.result.nModified == 0) {
            torrentdb.update({hash}, {$push: {files:{name : pth, date: new Date()}}}, function (err, res) {
                console.log('push', err, res.result.nModified);
            });
        }
    });
    setTimeout(function() {
        torrent.deleteOldFile(req);
    }, 5000);
}

torrent.deleteOldFile = function(req, callback) {
    var db = req.app.locals.db;
    var torrentdb = db.collection('torrent');

    var date = new Date(new Date()-30*24*60*60*1000);
    torrentdb.find({"files.date":{$lt: date}}, {hash: 1, files:1}).toArray(function(err, doc) {
        if (!err && doc) {
            for (var i = 0; i < doc.length; i++) {
                for (var j = 0; j < doc[i].files.length; j++) {
                    if (doc[i].files[j].date < date) {
                        console.log('deleteOldFile', doc[i].files[j].name, doc[i].files[j].date);
                        fs.unlinkSync(doc[i].files[j].name);
                        torrentdb.update({hash: doc[i].hash}, { $pull: { files: { name: doc[i].files[j].name, date: doc[i].files[j].date}}}, {multi: true}, function (err, res) {
                            console.log('delete', err, res.result.nModified);
                        });
                    }
                }
            }
        }
    });
}

module.exports = torrent;
