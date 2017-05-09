
var path = require('path');
var fs = require('fs');
var router = require('express').Router();
var MongoClient = require('mongodb').MongoClient
, assert = require('assert');

var url = 'mongodb://localhost:27017/myproject';

router.get('/', function(req, res) {
  console.log("petard");
  console.log(req.session.email);
  res.render("discover/html/discover.ejs");
});

module.exports = router;
