var express = require('express');

var app = express();
app.use(express.static('assets'));

app.get('/', function(req, res) {
  res.render('page.ejs');
});
app.get('/connexion', function(req, res) {
  res.render('login.ejs');
});
app.get('/register', function(req, res) {
  res.render('register.ejs');
});
app.get('/sous-sol', function(req, res) {
    res.setHeader('Content-Type', 'text/plain');
    res.end('Vous êtes dans la cave à vins, ces bouteilles sont à moi !');
});

app.get('/yo', function(req, res) {
    res.setHeader('Content-Type', 'text/plain');
    res.end('Hé ho, c\'est privé ici !');
});
app.get('/compter', function(req, res) {
    res.render('page.ejs');
});


app.listen(8080);
