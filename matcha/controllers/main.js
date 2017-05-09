var express = require('express');
var path = require('path');
var fs = require('fs');
var router = require('express').Router();
var MongoClient = require('mongodb').MongoClient
, assert = require('assert');
var crypto = require('crypto');



var app = express();
var sess;
var server = require('http').createServer(app);
var io = require('socket.io').listen(server);
var url = 'mongodb://localhost:27017/myproject';

router.post('/', function(req, res) {
  // res.setHeader('Content-Type', 'text/plain');
  // var birthday = req.body.remember;
  var email = req.body.email;
  var password = req.body.password;
  var hash = crypto.createHmac('sha256', password)
  .update('I love cupcakes')
  .digest('hex');
  // var password = req.body.password;

  MongoClient.connect(url, function(err, db) {
    assert.equal(null, err);
    console.log("Connected successfully to server");
    // Get the documents collection
    var collection = db.collection('clients');
    // Insert some documents
    collection.find(
      {email : email, password : hash}).toArray(function(err, docs){
        //    var activate = docs.param("activate");
        console.log(docs);
        //  console.log(docs[0].activate);
        if(docs.length > 0 && docs[0].activate == 1)
        {
          sess=req.session;
          sess.email= email;
          console.log(sess);
          console.log(email);
          console.log("refjeirfj");
          // var server = http.createServer(function(req1, res1) {
          //   console.log("raaaaaaa");
          //     // fs.readFile('mainpage.ejs', 'utf-8', function(error, content) {
          //     //     res1.writeHead(200, {"Content-Type": "text/html"});
          //     //     res1.end(content);
          //     // });
          // });
          // Chargement de socket.io
          // var io = require('socket.io').listen(server);
          res.render('main/html/mainpage.ejs');
          // Quand un client se connecte, on le note dans la console
          io.on('connection', function (socket) {
            io.emit('pierromoutarde', {"pierre": "moutarde"});
            console.log('Un client est connecté !');
          });
        }
        else {
          res.render('login.ejs');
        }
      });

      //  res.render('mainpage.ejs');
      db.close();
    });
    console.log("okokok");
    // console.log(email);
    // console.log(password);

  });
  module.exports = router;
