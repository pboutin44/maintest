var path = require('path');
var fs = require('fs');
var router = require('express').Router();
var Promise = require('bluebird');
var streamingLib = require('../models/streaming.js');
var parseTorrentFile = require('parse-torrent-file');

const yifysubtitles = require('yifysubtitles');



router.get('/', function(req, res) {

	if (req.session && req.session.pseudo)
		res.sendFile(path.resolve('./views/streaming/html/streaming.html'));
	else
		res.redirect('/');
});

router.post('/', function(req, res) {
	console.log("BODY" + JSON.stringify(req.body));
	yifysubtitles(req.body.imdbld, {path: './videos/subtitles',
																	langs: ['sq', 'ar', 'bn', 'pb', 'bg', 'zh', 'hr', 'cs', 'da', 'nl', 'en', 'et', 'fa', 'fi', 'fr', 'de', 'el', 'he', 'hu', 'id', 'it', 'ja', 'ko', 'lt', 'mk', 'ms', 'no', 'pl', 'pt', 'ro', 'ru', 'sr', 'sl', 'es', 'sv', 'th', 'tr', 'ur', 'uk', 'vi']
																	}
	).then(subs => {
					console.log(subs);
					res.json(subs);
				}
	).catch(err => console.log(err));
});

module.exports = router;
