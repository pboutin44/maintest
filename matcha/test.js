var express = require('express');
var bodyParser = require("body-parser");
var MongoClient = require('mongodb').MongoClient
  , assert = require('assert');
var crypto = require('crypto');
var nodemailer = require('nodemailer');
var fs = require('fs');
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
//var urlencodedParser = bodyParser.urlencoded({limit: '50mb', extended: true });
  app.use(bodyParser.urlencoded({limit: '50mb', extended: true }));

app.use(express.static('assets'));
app.use(express.static('/views'));
app.get('/', function(req, res) {
  res.render('page.ejs');
});
app.get('/connexion', function(req, res) {
  res.render('login.ejs');
});
app.get('/register', function(req, res) {
  res.render('register.ejs');
});
app.get('/confirmation', function(req, res) {
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
app.get('/email_send', function(req, res) {
  res.render('email_send.ejs');
});
app.get('/sous-sol', function(req, res) {
    res.setHeader('Content-Type', 'text/plain');
    res.end('Vous êtes dans la cave à vins, ces bouteilles sont à moi !');
});
app.post('/main', function(req, res) {
  // res.setHeader('Content-Type', 'text/plain');
  // var birthday = req.body.remember;
   var email = req.body.email;
   var password = req.body.password;
   var hash = crypto.createHmac('sha256', password)
                  .update('I love cupcakes')
                  .digest('hex');
  // var password = req.body.password;

  MongoClient.connect(url, function(err, db) {
    assert.equal(null, err);
    console.log("Connected successfully to server");
      // Get the documents collection
      var collection = db.collection('clients');
    // Insert some documents
    collection.find(
      {email : email, password : hash}).toArray(function(err, docs){
    //    var activate = docs.param("activate");
        console.log(docs);
      //  console.log(docs[0].activate);
          if(docs.length > 0 && docs[0].activate == 1)
          {
            res.render('mainpage.ejs');
          }
          else {
            res.render('login.ejs');
          }
      });

    //  res.render('mainpage.ejs');
    db.close();
  });
   console.log("okokok");
  // console.log(email);
  // console.log(password);

});
app.get('/forgot-password', function(req, res) {
  res.render('forgot-password.ejs');
});
app.get('/first_connection', function(req, res) {
  res.render('first_connection.ejs');
});
app.post('/ya', function(req, res) {
  //var name = req.body.photo;
  //console.log(name);
  console.log(req.body.image);
  // console.log(req.body.photo.src);

  res.render('first_connection.ejs');
});

app.post('/yo', function(req, res) {
//     res.setHeader('Content-Type', 'text/plain');
     var name = req.body.name;
     var birthday = req.body.Birthday;
     var email = req.body.email;
     var password = req.body.password;
     var male = req.body.inputRadioGender;
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
       console.log(name);
         // Get the documents collection
         var collection = db.collection('clients');
       // Insert some documents
       collection.find(
         {email : email}).toArray(function(err, docs){
           if(docs.length == 0)
           {
             collection.insertMany([
               {name : name, birthday : birthday, email : email, password : hash, token : token, activate : "0"}
             ]);
             fs.mkdirSync("./photos/"+email);

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


app.listen(8080);
