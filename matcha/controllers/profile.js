var path = require('path');
var fs = require('fs');
var router = require('express').Router();
var path = require('path');
var fs = require('fs');
var router = require('express').Router();
var MongoClient = require('mongodb').MongoClient
, assert = require('assert');
const StringDecoder = require('string_decoder').StringDecoder;
const decoder = new StringDecoder('utf8');

var url = 'mongodb://localhost:27017/myproject';

router.get('/', function(req, res) {
  console.log("petard");
  console.log(req.session.email);
  res.render("profile/html/profile.ejs");
});

router.post('/bizarre', function(req, res) {
  console.log("petouch");
  console.log(req.session.email);
  var email = {
    "email" : req.session.email
  }
  res.send(email);
});

router.get('/dodo2', function(req, res) {
  var photo1;
  var photo2;
  var photo3;
  var photo4;
  var photo5;
  console.log("grominet");
  fs.readFile('photos/'+req.query.email+'/photo1.png', 'utf8', (err, data) => {
  if (err) throw err;
  photo1 = data;
  });
  fs.readFile('photos/'+req.query.email+'/photo2.png', 'utf8', (err, data) => {
  if (err) throw err;
  photo2 = data;
  });
  fs.readFile('photos/'+req.query.email+'/photo3.png', 'utf8', (err, data) => {
  if (err) throw err;
  photo3 = data;
  });
  fs.readFile('photos/'+req.query.email+'/photo4.png', 'utf8', (err, data) => {
  if (err) throw err;
  photo4 = data;
  });
  fs.readFile('photos/'+req.query.email+'/photo5.png', 'utf8', (err, data) => {
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
      {email : req.query.email}).toArray(function(err, docs){
        if(docs.length == 0)
        {
          console.log(docs);
          console.log(email);
          console.log(token);
          console.log("coco")
          res.send('register.ejs');
        }
        else {
      //    console.log(photo1);
          docs[0].photo1 = photo1;
          docs[0].photo2 = photo2;
          docs[0].photo3 = photo3;
          docs[0].photo4 = photo4;
          docs[0].photo5 = photo5;
          res.send(docs);
          console.log("c'estgood");
    //      console.log(docs);
      //    $('.profile-user').append("erhfrthf")
        }
      });


      console.log("okokok");
      //db.close();
    });
  console.log("kamikaze");
});

router.get('/dodo', function(req, res) {
  var photo1;
  var photo2;
  var photo3;
  var photo4;
  var photo5;
  fs.readFile('photos/'+req.session.email+'/photo1.png', 'utf8', (err, data) => {
  if (err) throw err;
  photo1 = data;
  });
  fs.readFile('photos/'+req.session.email+'/photo2.png', 'utf8', (err, data) => {
  if (err) throw err;
  photo2 = data;
  });
  fs.readFile('photos/'+req.session.email+'/photo3.png', 'utf8', (err, data) => {
  if (err) throw err;
  photo3 = data;
  });
  fs.readFile('photos/'+req.session.email+'/photo4.png', 'utf8', (err, data) => {
  if (err) throw err;
  photo4 = data;
  });
  fs.readFile('photos/'+req.session.email+'/photo5.png', 'utf8', (err, data) => {
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
      //    console.log(photo1);
          docs[0].photo1 = photo1;
          docs[0].photo2 = photo2;
          docs[0].photo3 = photo3;
          docs[0].photo4 = photo4;
          docs[0].photo5 = photo5;
          res.send(docs);
          console.log("c'estgood");
    //      console.log(docs);
      //    $('.profile-user').append("erhfrthf")
        }
      });


      console.log("okokok");
      //db.close();
    });
  console.log("kamikaze");
});

router.post('/stock', function(req, res) {
   console.log("todo");
  var base64Data1 = req.param("photo1").replace(/^data:image\/png;base64,/, "");
  var base64Data2 = req.param("photo2").replace(/^data:image\/png;base64,/, "");
  var base64Data3 = req.param("photo3").replace(/^data:image\/png;base64,/, "");
  var base64Data4 = req.param("photo4").replace(/^data:image\/png;base64,/, "");
  var base64Data5 = req.param("photo5").replace(/^data:image\/png;base64,/, "");
  fs.writeFile('photos/'+req.session.email+'/photo1.png', base64Data1, 'base64', function (err) {
  if (err) throw err;
  console.log('It\'s saved!');
});
fs.writeFile('photos/'+req.session.email+'/photo2.png', base64Data2, 'base64', function (err) {
if (err) throw err;
console.log('It\'s saved!');
});
fs.writeFile('photos/'+req.session.email+'/photo3.png', base64Data3, 'base64', function (err) {
if (err) throw err;
console.log('It\'s saved!');
});
fs.writeFile('photos/'+req.session.email+'/photo4.png', base64Data4, 'base64', function (err) {
if (err) throw err;
console.log('It\'s saved!');
});
fs.writeFile('photos/'+req.session.email+'/photo5.png', base64Data5, 'base64', function (err) {
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
