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
  console.log("latable");
  //console.log(req.session.email);
  console.log(req.query.email);
  var someData = { message: 'hi' };
  res.render("chat/html/chat.ejs", {
        "status":req.query.email,
        "title":"home"
    });
});

router.get('/basic', function(req, res) {
  console.log("latable");
  //console.log(req.session.email);
  //console.log(req.query.email);
  //var someData = { message: 'hi' };
  res.send(req.session.email);
});

router.get('/historique', function(req, res) {
  MongoClient.connect(url, function(err, db) {
    assert.equal(null, err);
    console.log("Connected successfully to server");
    // Get the documents collection
    var collection = db.collection('conversation');
    // Insert some documents
    var email1 = req.query.email1;
    var email2 = req.query.email2;
    console.log(email1);
    console.log(email2);
    if(email2 < email1)
    {
      var key = email1+"-"+email2;
    }
    else {
      var key = email2+"-"+email1;
    }
    console.log("tomboy");
    console.log(key);
     collection.find(
       {key : key}).toArray(function(err, docs){
    console.log("pipo");
          console.log(docs);
         if(docs.length > 0)
         {
           res.send(docs);
         }
        else {
          res.send("ok");
        }
       });
    });
  console.log("Dino3");
  //res.send("ok");

});



//db.patients.insert({"nom":"jay gould" , "prenom":"stephen", "age": i})
router.get('/stock_chat', function(req, res) {
  MongoClient.connect(url, function(err, db) {
    assert.equal(null, err);
    console.log("Connected successfully to server");
    // Get the documents collection
    var collection = db.collection('conversation');
    // Insert some documents
    var messageto = req.query.messageto;
    var messagefrom = req.query.messagefrom;
    var message = req.query.message;
    if(messagefrom < messageto)
    {
      var key = messageto+"-"+messagefrom;
    }
    else {
      var key = messagefrom+"-"+messageto;
    }
     collection.find(
       {key : key}).toArray(function(err, docs){
    console.log("pipo");
          console.log(docs);
         if(docs.length > 0)
         {
           console.log("moquasin");
           var temp = docs[0].dialogue;
           var temp2 = docs[0].dialogue+"*_**"+messageto+"*_**"+message;
          collection.update({key : key}, {
            $set:{dialogue : temp2}
          });
         }
        else {
          var temp = messageto+"*_**"+message;
          collection.insert({key : key , dialogue : temp});
        }
       });
    });
  console.log("Dino3");
  res.send("ok");

});

module.exports = router;
