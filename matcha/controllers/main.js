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

router.get('/signout', function(req, res) {
  // if (config.debug)
  //   console.log("user.signout()");

  req.session.destroy(function (err) {
   console.log("tibone");
  // res.send("okok");
    res.redirect("/"); //Inside a callback… bulletproof!
  });
  //res.redirect("login.ejs");
  //res.send("ko");
});


router.get('/CurrentPosition', function(req, res) {
  console.log("Dino");
  var first_position = req.query.results[1].formatted_address;
//  var second_position = first_position.split(",");
  var final_position = first_position;
  MongoClient.connect(url, function(err, db) {
    assert.equal(null, err);
    console.log("Connected successfully to server");
    // Get the documents collection
    var collection = db.collection('clients');
    // Insert some documents
    var email = req.session.email;
    collection.find(
      {email : req.session.email}).toArray(function(err, docs){
        //    var activate = docs.param("activate");
        console.log(docs);
          console.log("nectare");
        if(docs.length > 0 && docs[0].activate == 1)
        {
          console.log("nectare2");
          collection.update({email : email}, {
            $set:{CurrentPosition : final_position}
          });
        }
        else {
          res.render('login.ejs');
        }
      });
      //  res.render('mainpage.ejs');
    //  db.close();
    });
  console.log("Dino3");
  res.send("ok");

});

router.get('/CurrentPosition2', function(req, res) {
  console.log("Dino");
  var first_position = req.query.results[2].formatted_address;
//  var second_position = first_position.split(",");
  var final_position = first_position;
  MongoClient.connect(url, function(err, db) {
    assert.equal(null, err);
    console.log("Connected successfully to server");
    // Get the documents collection
    var collection = db.collection('clients');
    // Insert some documents
    var email = req.session.email;
    collection.find(
      {email : req.session.email}).toArray(function(err, docs){
        //    var activate = docs.param("activate");
        console.log(docs);
          console.log("nectare");
        if(docs.length > 0 && docs[0].activate == 1)
        {
          console.log("nectare2");
          collection.update({email : email}, {
            $set:{CurrentPosition2 : final_position}
          });
        }
        else {
          res.render('login.ejs');
        }
      });
      //  res.render('mainpage.ejs');
    //  db.close();
    });
  console.log("Dino3");
  res.send("ok");

});

router.get('/connection', function(req, res) {
  console.log("Dino");
//  var first_position = req.query.results[1].formatted_address;
//  var second_position = first_position.split(",");
//  var final_position = first_position;
  var now = new Date();
  var annee   = now.getFullYear();
  var mois    = now.getMonth() + 1;
  var jour    = now.getDate();
  var heure   = now.getHours();
  var minute  = now.getMinutes();
  var seconde = now.getSeconds();
  var date = jour+"/"+mois+"/"+annee+"/"+heure+"h"+minute+"m"+seconde+"s";
  console.log("lafeteabamaco");
  console.log(date);
  MongoClient.connect(url, function(err, db) {
    assert.equal(null, err);
    console.log("Connected successfully to server");
    // Get the documents collection
    var collection = db.collection('clients');
    // Insert some documents
    var email = req.session.email;
    collection.find(
      {email : req.session.email}).toArray(function(err, docs){
        //    var activate = docs.param("activate");
        console.log(docs);
          console.log("nectare");
        if(docs.length > 0 && docs[0].activate == 1)
        {
          console.log("nectare2");
          collection.update({email : email}, {
            $set:{connection : "enligne"}
          });
        }
        else {
          res.render('login.ejs');
        }
      });
      //  res.render('mainpage.ejs');
    //  db.close();
    });
  console.log("Dino3");
  res.send("ok");

});

router.get('/disconnection', function(req, res) {
  console.log("Dino");
//  var first_position = req.query.results[1].formatted_address;
//  var second_position = first_position.split(",");
//  var final_position = first_position;
  var now = new Date();
  var annee   = now.getFullYear();
  var mois    = now.getMonth() + 1;
  var jour    = now.getDate();
  var heure   = now.getHours();
  var minute  = now.getMinutes();
  var seconde = now.getSeconds();
  var date = jour+"/"+mois+"/"+annee+"/"+heure+"h"+minute+"m"+seconde+"s";
  console.log("lafeteabamaco");
  console.log(date);
  MongoClient.connect(url, function(err, db) {
    assert.equal(null, err);
    console.log("Connected successfully to server");
    // Get the documents collection
    var collection = db.collection('clients');
    // Insert some documents
    var email = req.session.email;
    collection.find(
      {email : req.session.email}).toArray(function(err, docs){
        //    var activate = docs.param("activate");
        console.log(docs);
          console.log("nectare");
        if(docs.length > 0 && docs[0].activate == 1)
        {
          console.log("nectare2");
          collection.update({email : email}, {
            $set:{connection : date}
          });
        }
        else {
          res.render('login.ejs');
        }
      });
      //  res.render('mainpage.ejs');
    //  db.close();
    });
  console.log("Dino3");
  res.send("ok");

});











router.get('/popularity', function(req, res) {
  MongoClient.connect(url, function(err, db) {
    assert.equal(null, err);
    console.log("Connected successfully to server");
    // Get the documents collection
    var collection = db.collection('clients');
    // Insert some documents
    var email = req.session.email;
    collection.find(
      {email : req.session.email}).toArray(function(err, docs){
        //    var activate = docs.param("activate");
        res.send(docs)
      });
      //  res.render('mainpage.ejs');
    //  db.close();
    });
  //console.log("Dino3");
//  res.send("ok");

});
router.get('/', function (req, res) {
res.redirect('/')  
})
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

          res.render('main/html/mainpage.ejs');

        }
        else {
          res.render('login.ejs');
        }
      });
      //  res.render('mainpage.ejs');
      db.close();
    });
    console.log("okokok");

  });

  module.exports = router;
