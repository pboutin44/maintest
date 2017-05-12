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
//  console.log(req.session.email);
  res.render("login.ejs");
});
module.exports = router;
