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
  res.render("user_profil/html/user_profil.ejs", {
        "status":req.query.email,
        "title":"home"
    });
});

router.get('/information', function(req, res) {
  console.log("latable6");
  //console.log(req.session.email);
  var email = req.param("email");
   console.log(req.query);
   //console.log();
  console.log('bilbo');
  console.log(email);
  MongoClient.connect(url, function(err, db) {
    assert.equal(null, err);
    console.log("Connected successfully to server");
    // Get the documents collection
    var collection = db.collection('clients');
    // Insert some documents
    console.log("samara");
    console.log(email);
    collection.find(
      {email : email}).toArray(function(err, docs){
        if(docs.length == 0)
        {
          console.log(docs);
          console.log(email);
      //    console.log(token);
          console.log("coco")
          res.render('register.ejs');
        }
        else {
          //   alert("edokedk");
          collection.update({email : email}, {
            $addToSet:{visit : req.session.email}
          });
          res.send('ok');
          console.log("okok");
        }
      });


      console.log("okokok");
      //db.close();
    });
  // res.render("user_profil/html/user_profil.ejs", {
  //       "status":req.query.email,
  //       "title":"home"

});

module.exports = router;
