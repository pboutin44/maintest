var logger = require('winston');

// logger level { error: 0, warn: 1, info: 2, verbose: 3, debug: 4, silly: 5 }

logger.default.transports.console.colorize = true;
logger.level = 'verbose';
logger.add(logger.transports.File, {
 		filename: './bittorrentProtocol/torrent.log',
 		level: 'warn'
 });

module.exports = logger;
