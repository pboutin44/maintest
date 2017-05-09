var path = require('path');
var fs = require('fs');
var router = require('express').Router();
var path = require('path');
var fs = require('fs');
var router = require('express').Router();
var MongoClient = require('mongodb').MongoClient
, assert = require('assert');

var url = 'mongodb://localhost:27017/myproject';

router.get('/', function(req, res) {
  console.log("petard");
  console.log(req.session.email);
  res.render("profile/html/profile.ejs");
});
router.get('/dodo', function(req, res) {
  var photo1;
  var photo2;
  var photo3;
  var photo4;
  var photo5;
  fs.readFile('photos/'+req.session.email+'/photo1.txt', 'utf8', (err, data) => {
  if (err) throw err;
  photo1 = data;
  });
  fs.readFile('photos/'+req.session.email+'/photo2.txt', 'utf8', (err, data) => {
  if (err) throw err;
  photo2 = data;
  });
  fs.readFile('photos/'+req.session.email+'/photo3.txt', 'utf8', (err, data) => {
  if (err) throw err;
  photo3 = data;
  });
  fs.readFile('photos/'+req.session.email+'/photo4.txt', 'utf8', (err, data) => {
  if (err) throw err;
  photo4 = data;
  });
  fs.readFile('photos/'+req.session.email+'/photo5.txt', 'utf8', (err, data) => {
  if (err) throw err;
  photo5 = data;
  });
  console.log("photo4 :"+ photo4);
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
          res.send('register.ejs');
        }
        else {
          console.log(photo1);
          docs[0].photo1 = photo1;
          docs[0].photo2 = photo2;
          docs[0].photo3 = photo3;
          docs[0].photo4 = photo4;
          docs[0].photo5 = photo5;
          res.send(docs);
          console.log("c'estgood");
          console.log(docs);
      //    $('.profile-user').append("erhfrthf")
        }
      });


      console.log("okokok");
      //db.close();
    });
  console.log("kamikaze");
});

router.get('/stock', function(req, res) {
  fs.writeFile('photos/'+req.session.email+'/photo1.txt', req.param("photo1"), function (err) {
  if (err) throw err;
  console.log('It\'s saved!');
});
fs.writeFile('photos/'+req.session.email+'/photo2.txt', req.param("photo2"), function (err) {
if (err) throw err;
console.log('It\'s saved!');
});
fs.writeFile('photos/'+req.session.email+'/photo3.txt', req.param("photo3"), function (err) {
if (err) throw err;
console.log('It\'s saved!');
});
fs.writeFile('photos/'+req.session.email+'/photo4.txt', req.param("photo4"), function (err) {
if (err) throw err;
console.log('It\'s saved!');
});
fs.writeFile('photos/'+req.session.email+'/photo5.txt', req.param("photo5"), function (err) {
if (err) throw err;
console.log('It\'s saved!');
});

  MongoClient.connect(url, function(err, db) {
    assert.equal(null, err);
    console.log("Connected successfully to server");
    // Get the documents collection
      console.log(req.param("sexuality"));
    var collection = db.collection('clients');
    // Insert some documents
    collection.updateOne(
        { "email" : req.session.email },
        { $set: { "email" : req.param("email"), "sex" : req.param("sex"), "sexuality" : req.param("sexuality"), "pacinput" : req.param("pacinput"), "bio" : req.param("bio"), "tokenfield" : req.param("tokenfield"), "firstname" : req.param("firstname"), "surname" : req.param("surname")} }
     );

      res.send("ok");
      console.log("okokok");
      if(req.param("email"))
        fs.renameSync('photos/'+req.session.email, 'photos/'+req.param("email"))
      //db.close();
    });
  console.log("comique");
});

module.exports = router;
