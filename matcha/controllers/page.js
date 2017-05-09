var path = require('path');
var fs = require('fs');
var router = require('express').Router();


router.get('/', function(req, res) {
  res.render('page.ejs');
});

module.exports = router;
