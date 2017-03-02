  var express = require('express');
  var formidable = require('formidable');
  var path = require('path');

  var app = express();

  app.get('/', function (req, res){
    res.sendFile(path.resolve('./index.html'));
    //    res.render('page.ejs');
  });

  app.post('/', function (req, res){
    var form = new formidable.IncomingForm();

    form.parse(req);

    form.on('fileBegin', function (name, file){
      file.path = path.resolve(file.name);
    });

    form.on('file', function (name, file){
      console.log(file.name);
    });

    res.sendFile(path.resolve('./index.html'));
  });

  app.listen(3000);
