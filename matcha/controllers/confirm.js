var path = require('path');
var fs = require('fs');
var router = require('express').Router();
var MongoClient = require('mongodb').MongoClient
, assert = require('assert');

var url = 'mongodb://localhost:27017/myproject';

router.get('/', function(req, res) {
  var token = req.param("token");
  var email = req.param("email");
  console.log(token);
  MongoClient.connect(url, function(err, db) {
    assert.equal(null, err);
    console.log("Connected successfully to server");
    // Get the documents collection
    var collection = db.collection('clients');
    // Insert some documents
    collection.find(
      {email : email, token : token}).toArray(function(err, docs){
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
          collection.update({email : email, token : token}, {
            $set:{activate : "1"}
          });
          res.render('confirmation.ejs');
          console.log("okok");
        }
      });


      console.log("okokok");
      //db.close();
    });
    console.log(token);
    console.log(email);
});

module.exports = router;
