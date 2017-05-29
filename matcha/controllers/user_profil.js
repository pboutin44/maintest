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
var nodemailer = require('nodemailer');
//var dircompare = require('dir-compare');

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

router.get('/data', function(req, res) {
  //console.log("latable");
  //console.log(req.session.email);
  //console.log(req.query.email);
  //var someData = { message: 'hi' };
  res.send(req.session.email);
});

router.get('/maintips', function(req, res) {
  // console.log("latable");
  //console.log(req.session.email);
  function areBuffersEqual(bufA, bufB) {
    var len = bufA.length;
    if (len !== bufB.length) {
      return false;
    }
    for (var i = 0; i < len; i++) {
      if (bufA.readUInt8(i) !== bufB.readUInt8(i)) {
        return false;
      }
    }
    return true;
  }
  fs.readFile("./photos/"+req.session.email+"/photo1.png", function (err,data) {
    if (err) {
      return console.log(err);
    }
    fs.readFile("./global/photos/placeholder.png", function (err,data1) {
      if (err) {
        return console.log(err);
      }
      console.log(data);
      console.log(data1);
      if(areBuffersEqual(data, data1))
      {
        var flag = 1;
        console.log("c'estgagne");
      }
      else {
        var flag = 0;
      }

      MongoClient.connect(url, function(err, db) {
        assert.equal(null, err);
        // console.log("Connected successfully to server");
        // Get the documents collection
        var collection = db.collection('clients');
        // Insert some documents
        collection.find(
          {email : req.session.email}).toArray(function(err, docs){
            if(docs.length == 0)
            {
              // console.log(docs);
              // console.log(email);
              // console.log(token);
              // console.log("coco")
              res.send('register.ejs');
            }
            else {
              //    console.log(photo1);
              docs[0]["flag"] = flag;
              console.log("bordel");
              console.log(docs);
              res.send(docs);

              console.log("c'estgood");
              //      console.log(docs);
              //    $('.profile-user').append("erhfrthf")
            }
          });


          console.log("okokok");
          //db.close();
        });
      });

      // var path1 = "./photos/"+req.session.email+"/photo1.png";
      // var path1 = "./global/photos/placeholder.png";
      // var res = dircompare.compareSync(path1, path2, options);
      // console.log(res.equal);
      // console.log("verification");
      // console.log(data);
    });
    console.log("pellapliss");



  });

  router.get('/block', function(req, res) {
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
        {email : req.session.email}).toArray(function(err, docs){
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
            collection.update({email : req.session.email}, {
              $addToSet:{block : email}
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
              collection.update({email : req.session.email}, {
                $addToSet:{visitorof : email}
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

      router.get('/report', function(req, res) {
        console.log("latable6");
        //console.log(req.session.email);
        var email = req.param("email");
        console.log(req.query);
        //console.log();
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
          html: '<b>Hello world ?</b> email report :'+email // html body
        };

        // send mail with defined transport object
        transporter.sendMail(mailOptions, (error, info) => {
          if (error) {
            return console.log(error);
          }
          console.log('Message %s sent: %s', info.messageId, info.response);
        });
        // res.render("user_profil/html/user_profil.ejs", {
        //       "status":req.query.email,
        //       "title":"home"
        res.send("ok");

      });

      module.exports = router;
