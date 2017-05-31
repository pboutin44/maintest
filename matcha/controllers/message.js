
var path = require('path');
var fs = require('fs');
var router = require('express').Router();
var MongoClient = require('mongodb').MongoClient
, assert = require('assert');

var url = 'mongodb://localhost:27017/myproject';
// var url = require('url');
// var url_parts = url.parse(request.url, true);
// var query = url_parts.query;

router.get('/', function(req, res) {
  // console.log("petard");
  // console.log(req.session.email);
  res.render("message/html/message.ejs");
});

router.get('/like_someone', function(req, res) {
  console.log("letourisme");
  console.log(req.session.email);
  //console.log(req.params);
  console.log(req.query.email);
  MongoClient.connect(url, function(err, db) {
    assert.equal(null, err);
    console.log("Connected successfully to server");
    // Get the documents collection
    var collection = db.collection('clients');
    // Insert some documents
    collection.find(
      {email : req.session.email}).toArray(function(err, docs){
        if(docs.length == 0)
        {
          console.log(docs);
          console.log(email);
          console.log(token);
          console.log("coco")
          res.render('register.ejs');
        }
        else {

          //   alert("edokedk");
          collection.update({email : docs[0].email}, {
            $addToSet:{like : req.query.email}
          });
          // res.render('confirmation.ejs');
        }
      });
      collection.find(
        {email : req.query.email}).toArray(function(err, docs){
          if(docs.length == 0)
          {
            console.log(docs);
            console.log(email);
            console.log(token);
            console.log("coco")
            res.render('register.ejs');
          }
          else {

            //   alert("edokedk");
            collection.update({email : docs[0].email}, {
              $addToSet:{liked : req.session.email}
            });
            // res.render('confirmation.ejs');
          }
        });


      console.log("okokok");
      //db.close();
    });
  // console.log("petard");
  // console.log(req.session.email);
  // res.render("discover/html/discover.ejs");
});

router.get('/all_profil', function(req, res) {
  console.log("glace vanille");
  console.log(req.session.email);
  MongoClient.connect(url, function(err, db) {
    assert.equal(null, err);
    console.log("Connected successfully to server");
    // Get the documents collection
    var collection = db.collection('clients');
    // Insert some documents
    collection.find().toArray(function(err, docs){
        //    var activate = docs.param("activate");
      //  docs.mine = req.session.email;
        docs.push(req.session.email);
        console.log("cratere");
        console.log(docs);
        console.log("cratere1");
        res.send(docs)

      });

      //  res.render('mainpage.ejs');
      db.close();
    });
//   res.send("di");
});

router.get('/all_conversation', function(req, res) {
//  console.log("glace vanille");
  console.log(req.session.email);
  MongoClient.connect(url, function(err, db) {
    assert.equal(null, err);
    console.log("Connected successfully to server");
    // Get the documents collection
    var collection = db.collection('conversation');
    // Insert some documents
    collection.find().toArray(function(err, docs){
        //    var activate = docs.param("activate");
      //  docs.mine = req.session.email;
      //  docs.push(req.session.email);
        console.log("cratere");
        console.log(docs);
        console.log("cratere1");
        res.send(docs)

      });

      //  res.render('mainpage.ejs');
      db.close();
    });
//   res.send("di");
});

module.exports = router;
