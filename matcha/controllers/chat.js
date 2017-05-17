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

module.exports = router;
