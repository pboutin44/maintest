var express = require('express');
var bodyParser = require("body-parser");
var MongoClient = require('mongodb').MongoClient
, assert = require('assert');
var crypto = require('crypto');
var nodemailer = require('nodemailer');
var fs = require('fs');
var formidable = require('formidable');
var http = require('http');
var session = require('express-session');
var path = require('path');
//
var bonjourTest = require('./bonjourTest.js');

bonjourTest.echoBonjour();
//
//var formidable = require('express-formidable');
// Connection URL
var url = 'mongodb://localhost:27017/myproject';


// Use connect method to connect to the server
// var insertDocuments = function(db, callback) {
//   // Get the documents collection
//   var collection = db.collection('documents');
//   // Insert some documents
//   collection.insertMany([
//     {a : 1}, {a : 2}, {a : 3}
//   ], function(err, result) {
//     assert.equal(err, null);
//     assert.equal(3, result.result.n);
//     assert.equal(3, result.ops.length);
//     console.log("Inserted 3 documents into the collection");
//     callback(result);
//   });
// }

var app = express();
//var sess;
var server = require('http').createServer(app);
var io = require('socket.io').listen(server);
console.log("BONJOUR")
app.use(session({secret: 'ssshhhhh',resave: true,
saveUninitialized: true}));

//var urlencodedParser = bodyParser.urlencoded({limit: '50mb', extended: true });
app.use(bodyParser.urlencoded({limit: '50mb', extended: true }));
//app.use(formidable());
 app.use(express.static('assets'));
console.log('bonjourTest', path.resolve('.'))
app.use(express.static('./views'));
app.use(express.static('./photos'));
console.log('k')
//app.use( express.static(path.resolve('.')));

app.use('/', require('./controllers/register.js'));
app.use('/profile', require('./controllers/profile.js'));
 app.use('/discover', require('./controllers/discover.js'));
 app.use('/likedyou', require('./controllers/likedyou.js'));

app.use(function(err, req, res, next) {
  console.error('ERRROR !!!!', err);
  res.status(500).send('Something broke!');
});
io.on('connection', function (socket) {
  socket.on('join', function(fref){ console.log("dit bonjour");
  socket.broadcast.emit('toto', { receivers: 'everyone but socket'});
});
//  io.emit('pierromoutarde', {"pierre": "moutarde"});
  console.log('Un client est connecté !');
});
app.get('/test', function(req, res) {
  res.render('test.ejs');
});
app.get('/all_profil', function(req, res) {
  res.render('all_profil.ejs');
});
app.get('/connexion', function(req, res) {
  res.render('login.ejs');
});
 // app.get('/profile', function(req, res) {
 //   res.send('ouioui');
 // });
app.get('/register', function(req, res) {
  res.render('register.ejs');
});
app.get('/testFile', function(req, res) {
  res.sendFile(__dirname + '/views/all_profil.ejs');
})
app.use('/confirmation', require('./controllers/confirm.js'))
  app.get('/email_send', function(req, res) {
    res.render('email_send.ejs');
  });
  app.get('/sous-sol', function(req, res) {
    res.setHeader('Content-Type', 'text/plain');
    res.end('Vous êtes dans la cave à vins, ces bouteilles sont à moi !');
  });
  app.use('/main', require('./controllers/main.js'));
  app.get('/forgot-password', function(req, res) {
      res.render('forgot-password.ejs');
    });
    var G_token;
    var G_email;
    app.post('/confirmation_change', function(req, res) {
      console.log("erofjeroifjero");
      console.log(G_token);
      var email = G_email;
      var token = G_token;
      var password = req.body.password;
      var hash = crypto.createHmac('sha256', password)
      .update('I love cupcakes')
      .digest('hex');
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
                $set:{password : hash}
              });
              res.render('confirmation.ejs');
              console.log("okok");
            }
          });


          console.log("okokok");
          //db.close();
        });
    });

    app.get('/change', function(req, res) {
      var token = req.param("token");
      var email = req.param("email");
      G_token = req.param("token");
      G_email = req.param("email");
      res.render('change_password.ejs');
    });
    app.get('/first_connection', function(req, res) {
      res.render('first_connection.ejs');
    });
    app.post('/ya', function(req, res) {
      //var name = req.body.photo;
      //console.log(name);
      var form = new formidable.IncomingForm();

      form.parse(req);

      form.on('fileBegin', function (name, file){
        file.path = __dirname + '/uploads/' + file.name;
      });
      // console.log("kaka");
      form.on('file', function (name, file){
        console.log(file.name);
        //   console.log("groscasque");
      });
      res.render('first_connection.ejs');
    });
    app.post('/forgot', function(req, res) {
      var email = req.body.email;
      console.log(email);
      MongoClient.connect(url, function(err, db) {
        assert.equal(null, err);
    //    console.log("Connected successfully to server");
        // Get the documents collection
        var collection = db.collection('clients');
        // Insert some documents
        collection.find(
          {email : email}, {token:1}).toArray(function(err, docs){
            if(docs.length == 0)
            {
              console.log(docs);
          //    console.log(email);
          //    console.log(token);
              console.log("coco")
            //  res.render('register.ejs');
            }
            else {
              let transporter = nodemailer.createTransport({
                service: 'gmail',
                auth: {
                  user: 'testpierro1@gmail.com',
                  pass: 'Fritasse'
                }
              });

              // setup email data with unicode symbols
              let mailOptions = {
                from: '"Fred Foo 👻" <TheMatcha@Sbulba.com>', // sender address
                to: 'pierboutin@gmail.com', // list of receivers
                subject: 'changepassword', // Subject line
                text: 'Hello world ?', // plain text body
                html: '<b>Hello world ?</b> <a href="http://localhost:8080/change?token='+docs[0].token+'&email='+email+'">clique ici </a>' // html body
              };

              // send mail with defined transport object
              transporter.sendMail(mailOptions, (error, info) => {
                if (error) {
                  return console.log(error);
                }
                console.log('Message %s sent: %s', info.messageId, info.response);
              });
              //   alert("edokedk");
    //          collection.update({email : email, token : token}, {
      //          $set:{activate : "1"}
        //      });
          //    res.render('confirmation.ejs');
              console.log(docs[0].token);
        //      console.log(docs.token);
              //console.log(token);
              console.log("okok");
              res.render('login.ejs');
            }
          });


        //  console.log("okokok");
          //db.close();
        });
    });
    app.post('/yo', function(req, res) {
      //     res.setHeader('Content-Type', 'text/plain');
      var login = req.body.login;
      var firstname = req.body.firstname;
      var surname = req.body.surname;
      var birthday = req.body.Birthday;
      var email = req.body.email;
      var password = req.body.password;
    //  var male = req.body.inputRadioGender;
      console.log("3fpo34kf");
      console.log(req.body.inputRadioGender);
      //var femmale = req.params.inputRadioGender2;
      var token = crypto.randomBytes(64).toString('hex');
      var hash = crypto.createHmac('sha256', password)
      .update('I love cupcakes')
      .digest('hex');
      //   console.log(p1);
      MongoClient.connect(url, function(err, db) {
        assert.equal(null, err);
        console.log("Connected successfully to server");
        console.log(surname);
        // Get the documents collection
        var collection = db.collection('clients');
        // Insert some documents
        collection.find(
          {email : email}).toArray(function(err, docs){
            if(docs.length == 0)
            {
              collection.insertMany([
                {login : login, firstname : firstname, surname : surname, birthday : birthday, email : email, password : hash, token : token, activate : "0"}
              ]);
              fs.mkdirSync("./photos/"+email);
              fs.openSync("./photos/"+email+"/photo1.png", 'w');
              fs.openSync("./photos/"+email+"/photo2.png", 'w');
              fs.openSync("./photos/"+email+"/photo3.png", 'w');
              fs.openSync("./photos/"+email+"/photo4.png", 'w');
              fs.openSync("./photos/"+email+"/photo5.png", 'w');
              let transporter = nodemailer.createTransport({
                service: 'gmail',
                auth: {
                  user: 'testpierro1@gmail.com',
                  pass: 'Fritasse'
                }
              });

              // setup email data with unicode symbols
              let mailOptions = {
                from: '"Fred Foo 👻" <TheMatcha@Sbulba.com>', // sender address
                to: 'pierboutin@gmail.com', // list of receivers
                subject: 'Hello ✔', // Subject line
                text: 'Hello world ?', // plain text body
                html: '<b>Hello world ?</b> <a href="http://localhost:8080/confirmation?token='+token+'&email='+email+'">clique ici </a>' // html body
              };

              // send mail with defined transport object
              transporter.sendMail(mailOptions, (error, info) => {
                if (error) {
                  return console.log(error);
                }
                console.log('Message %s sent: %s', info.messageId, info.response);
              });
              res.render('email_send.ejs');
            }
            else {
              //   alert("edokedk");
              console.log("okok");
            }
          });


          console.log("okokok");
          //db.close();
        });

        // console.log("post received");
        //  res.end("b"+male);
      });
      app.get('/compter', function(req, res) {
        res.render('page.ejs');
      });

      server.listen(8080);
