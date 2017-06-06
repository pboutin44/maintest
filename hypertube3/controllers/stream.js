var router = require('express').Router();
var path = require('path');
var fs = require('fs');
var torrent = require('../models/torrent.js');
var Converter = require('../models/converter.js');

var ffmpeg = require('fluent-ffmpeg');

//start download file, return status about file (dlpercent, encoding available, encoding percent)
router.get('/:hash/:file/webm', function (req, res) {
    console.log(req.params.hash, req.params.file);
    console.log(path.parse(req.params.file).ext.replace('.', ''), 'is video:', Converter.videoFormats.indexOf(path.parse(req.params.file).ext.replace('.', '')) >= 0);

    if (Converter.videoFormats.indexOf(path.parse(req.params.file).ext.replace('.', '')) < 0) {
        return res.status(404).end();
    }

    var hash = req.params.hash,
        file = req.params.file,
        pth = 'torrent/files/'+hash+'.torrent';

    var reso = parseInt(req.query.res) || 0,
        fps = parseInt(req.query.fps) || 0;

    var cancelRequest = false;
    req.on('close', (err) => {
        console.log('----- cancel -----');
        cancelRequest = true;
        return res.status(404).end();
    });

    var parts = [0,0], start, end, chunksize, total;

    function calculSize(size, log, currentLen) {
        if (req.headers.range)
            parts = req.headers.range.replace(/bytes=/, "").split("-");
        total = size,
        start = parseInt(parts[0]),
        end = (parts[1] ? parseInt(parts[1]) : currentLen/*start+(1024*1024)*/-1);

        start = (start < total ? start : total-1);
        end = (end < total ? end : total-1);
        start = (start >= 0 ? start : 0);
        end = (end >= 0 ? end : 0);
        chunksize = (end-start)+1;
        if (log)
            console.log('calculate range: ' + start + ' - ' + end + '/' + total + ' = ' + chunksize);
    }
    function send(pth, size) {
        console.log('=================================');
        console.log('Header range:', req.headers.range);
        console.log('Sent: bytes ' + start + '-' + end+'/'+(size ? size : '*'), 'chunksize:', chunksize);
        torrent.fileView(req, hash, pth);
        if (cancelRequest) return;
        res.writeHead(206, {
            'Content-Range' : 'bytes ' + start + '-' + end+(size ? '/'+size : '/*'),//+(end+1000),// + '/' + total+10000,
            'Accept-Ranges' : 'bytes',
            'Content-Length': chunksize,
            'Content-Type' : 'video/webm'
        });
        var file = fs.createReadStream(pth, {start: start, end: end});
        file.pipe(res);
        console.log('SEND !!!');
    }

    var key = torrent.startDownload(pth, file);
    var ppp = function() {
        torrent.getFile(key, reso, fps, (data) => {
            if (data) {
                var statFile = fs.statSync(data.path);

                console.log('data.percent:', data.percent);
                if (data.percent > 0) {
                    calculSize(statFile.size, false, statFile.size);
                    if (!cancelRequest)
                        send(data.path, (data.percent == 100 ? statFile.size : false));
                }
                else {
                    setTimeout(ppp, 500);
                }
            }
            else {
                console.log('data is null');
                return res.status(404).end();
            }
        });
    }
    ppp();
});

router.get('/:hash/:file', function (req, res) {
    var hash = req.params.hash,
        file = req.params.file,
        pth = 'torrent/files/'+hash+'.torrent';

    var key = torrent.startDownload(pth, file);
    torrent.getAvailableSettings(key, (infos) => {
        //console.log('infos', infos);
        res.jsonp(infos);
    });
});

    /*
    var parts = [0,0], start, end, chunksize, total;
    if (torrent.isDownloading(key)) {
        torrent.actualdl[key].downloader.filesInfo(null, {verbose: false}, function(fileInfos) {
            //console.log(fileInfos);
            if (cancelRequest) return;
        //    console.log(fileInfos.percent);
            var filePath = fileInfos.dlPath;//torrent.actualdl[key].downloader.filePath;//fileInfos.dlPath;
            stream.isStreamable(filePath, (bool)=>{
                //console.log('isStreamable',bool, filePath);
                if (bool && bool.format && bool.format.duration) {

                    /*
                    var speed = bool.format.size;
                    setTimeout(function(){
                        console.log(actualdl[key].downloader.fileLength, (bool.format.size-speed)/5, (actualdl[key].downloader.fileLength-bool.format.size)/((bool.format.size-speed)/5)/60);
                    }, 5000);* /

                    calculSize(bool.format.size, true, fileInfos.currentLen);

                    if (!cancelRequest)
                        send(filePath, torrent.actualdl[key].downloader.fileLength);
                }
            });
        });
    }
    else {
        var inter = setInterval(function() {
            console.log('connection close:', cancelRequest, torrent.actualdl[key].downloader.fileLength);
            if (cancelRequest)
                return clearInterval(inter);
            torrent.actualdl[key].downloader.filesInfo(null, {verbose: false}, function(fileInfos) {
            //    console.log(fileInfos);
            //    console.log(fileInfos.percent);
            var filePath = fileInfos.dlPath;//torrent.actualdl[key].downloader.filePath;//fileInfos.dlPath;
                stream.isStreamable(filePath, (bool)=>{
                    //console.log('isStreamable',(!!bool?bool.format:bool), filePath);
                    if (bool && bool.format && bool.format.duration) {

                        /*
                        var speed = bool.format.size;
                        setTimeout(function(){
                            console.log(actualdl[key].downloader.fileLength, (bool.format.size-speed)/5, (actualdl[key].downloader.fileLength-bool.format.size)/((bool.format.size-speed)/5)/60);
                        }, 5000);* /

                        calculSize(bool.format.size, true, fileInfos.currentLen);

                        clearInterval(inter);
                        if (!cancelRequest)
                            send(filePath, torrent.actualdl[key].downloader.fileLength);
                    }
                });
            });
        }, 5000);
    }*/
//});

router.get('/:hash', function (req, res, next) {
    if (!req.params.hash) {
        console.log('lolilol 404 1');
        //404
        return next();//res.status(404).end();
    }
    torrent.get(req, {hash: req.params.hash}, (obj) => {
        if (obj.success && obj.doc) {
            console.log(obj.doc);
            //res.jsonp(obj.doc);
            res.sendFile(path.resolve('views/stream/html/index.html'));
        }
        else {
            console.log('lolilol 404');
            //404
            return next();//res.status(404).end();
        }
    });
});

module.exports = router;
