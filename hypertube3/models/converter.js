var parseTorrentFile = require('parse-torrent-file'),
    request = require('request'),
    crypto = require('crypto'),
    fs = require('fs');
var ffmpeg = require('fluent-ffmpeg');
//var torrent = require('../models/torrent.js');
var mkdirp = require('mkdirp');
var Readable = require('stream').Readable;

var DEBUG = false;

var Converter = function(pth, name, finalLen) {
    this.originalDir = pth;
    this.nameFile = name;
    this.convertedDir = this.originalDir.replace('/downloaded', '/converted');
    mkdirp.sync(this.convertedDir);
    this.converters = [];
    this.percent = 0;
    this.currentLen = 0;
    this.duration = -1;
    this.finalLen = finalLen;
    this.videoSettings = [
        //360p:
        { res:360, mode:'low', bitrate:512 },
        { res:360, mode:'high', bitrate:1024 },
        //480p:
        { res:480, mode:'low', bitrate:1.5*1024 },
        { res:480, mode:'high', bitrate:2*1024 },
        //720p:
        { res:720, mode:'low', bitrate:3*1024 },
        { res:720, mode:'high', bitrate:4*1024 },
        //1080p:
        { res:1080, mode:'low', bitrate:5*1024 },
        { res:1080, mode:'high', bitrate:6*1024 },
        /*/1440p:
        { res:1440, fps:30, bitrate:'8m' },
        { res:1440, fps:60, bitrate:'10m' },
        //4K:
        { res:2160, fps:30, bitrate:'16m' },
        { res:2160, fps:60, bitrate:'18m' },
        //8K:
        { res:4320, fps:30, bitrate:'20m' },
        { res:4320, fps:60, bitrate:'22m' },
        */
    ];

    this.update = function(len) {
        this.currentLen = len;
        this.percent = Math.round((this.currentLen * 100 / this.finalLen) * 100) / 100;
    }

    this.finished = function() {
        this.currentLen = this.finalLen;
        this.percent = Math.round((this.currentLen * 100 / this.finalLen) * 100) / 100;
    }

    this.getInfos = function(cb) {
        this.getMetadata(this.originalDir+'/'+this.nameFile, (metadata) => {
            if (metadata && metadata.streams && metadata.format) {
                var index = 0;
                for (var i = 0; i < metadata.streams.length; i++) {
                    if (metadata.streams[i].codec_type == 'video') {
                        index = i;
                    }
                }
                var infos = {
                    width: metadata.streams[index].width,
                    height: metadata.streams[index].height,
                    duration: metadata.format.duration
                };
                this.duration = metadata.format.duration;
                infos.fps = metadata.streams[index].avg_frame_rate.split('/');
                infos.fps = Math.round(parseInt(infos.fps[0]) / parseInt(infos.fps[1]));
                //console.log(infos);
                cb(infos);
            }
            else {
                cb(null);
            }
        });
    }

    this.getMetadata = function(path, cb) {
        ffmpeg.ffprobe(path, (err, metadata) => {
            if (err) {
                //console.log(err, path);
                cb(null);
            }
            else {
                //console.log(metadata);
                cb(metadata);
            }
        });
    }

    this.availableSettings = function(cb) {
        this.getInfos((infos) => {
            //console.log(infos);
            var ret = {success: false};
            if (infos) {
                ret = {choices:[], success: true};
                for (var i = 0; i < this.videoSettings.length; i++) {
                    var obj = {};
                    if (this.videoSettings[i].res <= infos.height) {
                        obj.res = this.videoSettings[i].res;
                    }
                    else if (i > 0 && this.videoSettings[i - 1].res < infos.height) {
                        obj.res = infos.height;
                        obj.res = (obj.res > 1080 ? 1080 : obj.res);
                    }
                    else if (i == 0) {
                        obj.res = infos.height;
                    }
                    if (this.videoSettings[i].mode == 'low') {
                        obj.fps = infos.fps;
                        obj.fps = (obj.fps > 30 ? 30 : obj.fps);
                        obj.bitrate = this.videoSettings[i].bitrate;
                    }
                    else if (this.videoSettings[i].mode == 'high' && infos.fps > 30) {
                        obj.fps = infos.fps;
                        obj.fps = (obj.fps > 60 ? 60 : obj.fps);
                        obj.bitrate = this.videoSettings[i].bitrate;
                    }
                    if (obj.res && obj.fps && obj.bitrate) {
                        ret.choices.push(obj);
                    }
                }
                for (let i = 0; i < ret.choices.length; i++) {
                    if (this.getData(ret.choices[i]) === null) {
                        this.fileExist(ret.choices[i], (bool) => {
                            var add = this.converters.length;
                            if (bool) {
                                console.log('File conveted exist already');
                                this.converters.push({
                                    path: this.convertedDir+'/'+this.nameFile+'['+ret.choices[i].res+'p'+ret.choices[i].fps+'fps].webm',
                                    settings: ret.choices[i],
                                    percent: 100,
                                    secStreamable: this.duration,
                                });
                            }
                        });
                    }
                }
            }
            cb(ret);
        });
    }

    this.checkSettings = function(settings, cb) {
        this.availableSettings((obj) => {
            for (var i = 0; i < obj.choices.length; i++) {
                if (obj.choices[i].res == settings.res && obj.choices[i].fps && settings.fps) {
                    return cb(obj.choices[i]);
                }
            }
            cb(null);
        });
    }

    this.getData = function(settings) {
        var add = this.converters.length;
        for (var i = 0; i < add; i++) {
            if (this.converters[i].settings.res == settings.res &&
                this.converters[i].settings.fps == settings.fps &&
                this.converters[i].settings.bitrate == settings.bitrate) {
                //console.log('>>> find !!!');
                return this.converters[i];
            }
        }
        return null;
    }

    this.fileExist = function(settings, cb) {
        var pth = this.convertedDir+'/'+this.nameFile+'['+settings.res+'p'+settings.fps+'fps].webm';
        this.getMetadata(pth, (metadata) => {
            if (metadata && metadata.format && parseInt(metadata.format.duration) == parseInt(this.duration)) {
                cb(true);
            }
            else {
                cb(false);
            }
        });
    }

    this.autoUpdateEncoder = function(index) {
        console.log('Pipe ready !', index);
        var bloop = (i) => {
            if (!this.converters[i].ready || this.converters[i].waitingData > (2.5*1024*1024)) {
                return setTimeout(() => { bloop(i); }, 500);
            }
            else if (this.converters[i].encodedData == this.finalLen) {
                console.log('Push END !');
                this.converters[i].streamData.push(null);
                console.log('passe end', this.converters[i].encodedData, this.converters[i].lastLen, this.finalLen);
                return;
            }
            if ((this.currentLen < this.finalLen && this.currentLen > this.converters[i].lastLen + (5*1024*1024)) || this.currentLen == this.finalLen) {
                if (this.converters[i].lastLen == this.finalLen) {
                    return setTimeout(() => { bloop(i); }, 500);
                }
                var start = this.converters[i].lastLen;
                var end = this.currentLen - 1;
                if (this.currentLen > this.converters[i].lastLen + (5*1024*1024))
                end = this.converters[i].lastLen + (5*1024*1024);

                if (DEBUG) {
                    console.log('Pipe', end - start, 'bytes');
                }
                var read = fs.createReadStream(this.originalDir+'/'+this.nameFile, {start: start, end: end});
                read.on('data', (buff) => {
                    this.converters[i].waitingData += buff.length;
                    //console.log('######## data add !!!', buff.length, this.converters[i].waitingData);
                    this.converters[i].streamData.push(buff);
                })
                .on('end', () => {
                    if (this.currentLen > this.converters[i].lastLen + (5*1024*1024)) {
                        this.converters[i].lastLen += (5*1024*1024) + 1;
                    }
                    else {
                        this.converters[i].lastLen = this.currentLen;
                    }
                    return setTimeout(() => { bloop(i); }, 500);
                });
            }
            else {
                return setTimeout(() => { bloop(i); }, 500);
            }
        }
        bloop(index);
    }

    this.addEncoder = function(settings, cb) {
        var add = this.converters.length;
        var data = this.getData(settings);
        if (data !== null) {
            return cb(data);
        }
        this.fileExist(settings, (bool) => {
            if (bool) {
                console.log('File conveted exist already');
                this.converters.push({
                    path: this.convertedDir+'/'+this.nameFile+'['+settings.res+'p'+settings.fps+'fps].webm',
                    settings,
                    percent: 100,
                    secStreamable: this.duration,
                });
                return cb(this.converters[add]);
            }
            else {
                this.converters.push({
                    streamData: new Readable({read(){}}),
                    waitingData: 0,
                    encodedData: 0,
                    lastLen: 0,
                    ready: false,
                    startTime: 0,
                    endTime: 0,
                    path: this.convertedDir+'/'+this.nameFile+'['+settings.res+'p'+settings.fps+'fps].webm',
                    settings,
                    percent: 0,
                    secStreamable: 0,
                });
                this.runEncoder(add);
                this.autoUpdateEncoder(add);
                return cb(this.converters[add]);
            }
        });
    }

    this.runEncoder = function(index) {
        console.log(':::::::::::::::::::', 'Run encoder', ':::::::::::::::::::');

        var write = fs.createWriteStream(this.converters[index].path);

        this.converters[index].streamData.on('data', (chunk) => {
            this.converters[index].encodedData += chunk.length;
            this.converters[index].waitingData -= chunk.length;
            //console.log('######## data del !!!', chunk.length, this.converters[index].waitingData);
        });

        ffmpeg(this.converters[index].streamData)
        .addInputOptions([
            //'-re'
        ])
        .addOptions([
            '-crf 18'
        ])
        .videoCodec('libvpx')
        .audioCodec('libvorbis')
        .format('webm')
        .videoBitrate(this.converters[index].settings.bitrate+'k')
        .audioBitrate('196k')
        .fps(this.converters[index].settings.fps)
        .size('?x'+this.converters[index].settings.res)
        .outputOptions([
            '-threads 2',
            '-cpu-used 0',
            '-deadline realtime',
            '-error-resilient 1'
        ])
        .on('start', (cmd) => {
            console.log('ffmpeg command:', cmd);
            this.converters[index].ready = true;
            this.converters[index].startTime = new Date();
        })
        .on('end', () => {
            this.converters[index].percent = 100;
            this.converters[index].endTime = new Date();
            console.log('Processing: complete !');
            var t = this.converters[index].endTime - this.converters[index].startTime;
            var m = parseInt(Math.round(t/1000)/60);
            var s = parseInt(Math.round(t/1000)%60);
            console.log('Time:', m+'min', s+'sec');
            this.secondPass(index);
        })
        .on('progress', (progress) => {
            if (this.duration > 0) {
                var percent = Math.round((this.converters[index].encodedData * 100 / this.finalLen) * 100) / 100;
                var secStreamable = Math.round((progress.frames / this.converters[index].settings.fps) * 100) / 100;
                this.converters[index].percent = percent;
                this.converters[index].secStreamable = secStreamable;
                Math.round((progress.frames / this.converters[index].settings.fps) * 100) / 100
                if (DEBUG) {
                    console.log('Processing: ' + percent + '% done', '-', secStreamable, 'sec streamable');
                }
            }
        })
        .on('error', (err) => {
            console.log("cant convert the movie");
            console.log(err);
        })
        .pipe(write);
    }

    this.secondPass = function(index) {
        console.log(':::::::::::::::::::', 'Run pass 2', ':::::::::::::::::::');

        ffmpeg(this.converters[index].path)
        .videoCodec('copy')
        .audioCodec('copy')
        .format('webm')
        .output(this.converters[index].path+'(pass2)')
        .on('end', () => {
            setTimeout(()=>{
                console.log('Processing: pass 2 complete !');
                fs.unlinkSync(this.converters[index].path);
                fs.renameSync(this.converters[index].path+'(pass2)', this.converters[index].path);
            }, 1000);
        })
        .on('start', (cmd) => {
            console.log('ffmpeg command:', cmd);
        })
        .on('progress', (progress) => {
            console.log('Processing: pass 2 ', progress, '% done');
        })
        .on('error', (err) => {
            console.log("cant convert the movie");
            console.log(err);
        })
        .run();
    }
};

Converter.videoFormats = [
    'mp4',
    'avi',
    'mov',
    'mkv',
    'mpeg',
    'flv',
    'wmv',
    'webm'
];

/*
Converter.readOriginalFile = function(pth, settings) {
    var streamData = new Readable({read(){}});
    var lastLen = 0;

    this.dwnlds[key].downloader.filesInfo(null, {verbose: false}, function(fileInfos) {
        this.dwnlds[key].relativePath = fileInfos.relativePath;
        this.dwnlds[key].name = fileInfos.name;
        this.dwnlds[key].convertedPath = this.dwnlds[key].relativePath.replace('/downloaded', '/converted');
        this.dwnlds[key].percent = fileInfos.percent;

        //console.log(fileInfos.percent, fileInfos.firstPieceMissing, fileInfos.currentLen, torrent.actualdl[key].lstLen+1024*1024);

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
        }
    });
});*/

/*
Converter.Converter = function(pth, res) {
    this.res = res.res;
    this.fps = res.fps;
    this.originalFile = pth;
    var f = path.parse(this.originalFile);
    this.convertedFile = f.dir+'/'+f.name+' - '+this.res+'p '+this.fps+'fps'+f.ext;
    //quality: 0 is lossless, 23 is default, and 51 is worst possible
    this.quality = 25;
    this.end = false;
    this.bytesWritten = 0;
    this.progress = 0;
    this.metadata = null;
    this.streamable = false;
    /*this.infos = {
        path: pth,
        convertedPath: cvrt,
        end: false,
        framerate:30,
        width:1920,
        //start:'00:00:00',
        //duration:'00:00:00',
        bytesWritten: 0,
        progress: 0,
    };* /
    //this.bytesWritten = 0;

    ffmpeg.ffprobe(this.originalFile, (err, metadata) => {
        if (!err && metadata)
            this.metadata = metadata.format;
        //console.log(metadata);
    });
/*
    this.infos.write = fs.createWriteStream(this.infos.convertedPath);
    this.infos.write.on('finish', () => {
        this.infos.end = true;
    })
    .on('pipe', (src,a,b,c) => {
        console.log('Writing start');
        this.infos.status = setInterval(()=>{
            //console.log('Converted:', this.infos.bytesWritten, this.infos.convertedPath);
            if (this.infos.end) {
                clearInterval(this.infos.status);
                console.log('File converted !'+this.infos.convertedPath);
            }
        },250);
    });* /
    var prog = -1;

    var proc = ffmpeg(this.originalFile)
    .inputOptions([
        //'-ss '+obj.start
        '-re'
    ])
    .addOptions([
        //'-map 0',
        '-movflags +faststart',
        //'-movflags isml+frag_keyframe',
        '-r '+this.fps,
        //'-vf scale='+this.infos.width+':-1',
        //'-to '+this.infos.duration,
        '-crf '+this.quality,
        '-preset veryfast',
        //    '-preset ultrafast',
        //    '-flags',
        //    '-global_header',
    ])
    .format('mp4')
    .videoCodec('libx264')
    //.videoBitrate(3*1024)
    .audioCodec('aac')
    .audioBitrate('128k')
    .size('?x'+this.res)
    .on('start', (cmd) => {
        console.log('ffmpeg command:', cmd);
    })
    .on('progress', (progress) => {
        this.progress = progress.percent;
        ffmpeg.ffprobe(this.convertedFile, (err, metadata) => {
            //this.infos.metadata = metadata.format;
            //this.streamable = true;
            if (!err) {
                this.bytesWritten = metadata.format.size;
                //console.log(metadata.format.duration, metadata.format.size);
                console.log('Processing: '+ path.parse(this.convertedFile).name + ' ' + Math.round(this.progress) + '% done', 'duration:', Math.round(metadata.format.duration), 'sec ', 'size:', metadata.format.size);
            }
            else if (Math.round(this.progress) % 10 == 0 && Math.round(this.progress) > prog) {
                console.log('Processing: '+ path.parse(this.convertedFile).name + ' ' + Math.round(this.progress) + '% done');
                prog = Math.round(this.progress);
            }
        });
    //    if (Math.round(progress.percent) % 10 == 0)
    })
    .on('end', (a,b,c) => {
        this.end = true;
        this.progress = 100;
        ffmpeg.ffprobe(this.convertedFile, (err, metadata) => {
            if (!err) {
                this.bytesWritten = metadata.format.size;
                console.log('Ended: ' + path.parse(this.convertedFile).name + ' ' + Math.round(this.progress) + '% done', 'duration:', Math.round(metadata.format.duration), 'sec ', 'size:', metadata.format.size);
            }
            else
                console.log('Ended: ' + path.parse(this.convertedFile).name + ' ' + Math.round(this.progress) + '% done');
        });
        console.log('File converted !', this.convertedFile);
        //console.log(this.originalFile+' has been converted succesfully');
    })
    .on('error', (err, stdout, stderr) => {
        console.log('an error happened: ' + err.message);
        //console.log(stdout);
        console.log(stderr);
    })
    //.pipe(this.infos.write);
    .save(this.convertedFile);
    //* /
    return this;
}
*/
/*

Converter.resolution = function(url, callback) {
    var name = './stream/files/tmp-'+sha1(url+new Date())+'.stream';
    request.get(url, function(err, res) {
        callback(name);
    }).pipe(fs.createWriteStream(name));
}
*/
module.exports = Converter;
