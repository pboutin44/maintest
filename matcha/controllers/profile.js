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
  console.log(req.session.email);
  res.render("profile/html/profile.ejs");
});

router.post('/bizarre', function(req, res) {
  console.log("petouch");
  console.log(req.session.email);
  var email = {
    "email" : req.session.email
  }
  res.send(email);
});

router.get('/notif', function(req, res) {
  console.log("petouch");
  console.log(req.session.email);
  var email = {
    "email" : req.session.email
  }
  MongoClient.connect(url, function(err, db) {
    assert.equal(null, err);
    console.log("Connected successfully to server");
    // Get the documents collection
    console.log(req.param("sexuality"));
    var collection = db.collection('clients');
    // Insert some documents
    collection.update(
      { "email" : req.session.email },
      { $unset : { notif : ""} }
    );
  });
  res.send(email);
});

router.get('/info2', function(req, res) {
  console.log("petouch");
  console.log(req.session.email);
  var email = {
    "email" : req.session.email
  }
  MongoClient.connect(url, function(err, db) {
    assert.equal(null, err);
    console.log("Connected successfully to server");
    // Get the documents collection
    console.log(req.param("sexuality"));
    var collection = db.collection('clients');
    // Insert some documents
    collection.find({ "email" : req.session.email }).toArray(function(err, docs){
      res.send(docs);


    });
  });
});




router.post('/findplace', function(req, res) {
  console.log("petouch");
  console.log(req.session.email);
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
  var i = 1;
  var k = 0;
  var test1 = 1;
  var test2 = 2;
  var test3 = 3;
  var test4 = 4;
  var test5 = 5;

  var table = [];
  fs.readFile("./global/photos/placeholder.png", function (err,data) {
    if (err) {
      return console.log(err);
    }
    while(i < 6)
    {

      var p = new Promise((resolve, reject) => {
        fs.readFile("./photos/"+req.session.email+"/photo"+i+".png", function (err,data1) {
          if (err) {
            return console.log(err);
          }
          if(areBuffersEqual(data, data1))
          {

            resolve(1);
          }
          else {
            resolve("-22666");
          }

      });
    });
    table.push(p);

      i++;
    }
    Promise.all(table).then(values => {
      console.log("dalmatien");
  console.log(values);
  res.send(values);
});
  })
//  res.send(email);
});

router.get('/dodo2', function(req, res) {
  var photo1;
  var photo2;
  var photo3;
  var photo4;
  var photo5;
  console.log("grominet");
  fs.readFile('photos/'+req.query.email+'/photo1.png', 'utf8', (err, data) => {
    if (err) throw err;
    photo1 = data;
  });
  fs.readFile('photos/'+req.query.email+'/photo2.png', 'utf8', (err, data) => {
    if (err) throw err;
    photo2 = data;
  });
  fs.readFile('photos/'+req.query.email+'/photo3.png', 'utf8', (err, data) => {
    if (err) throw err;
    photo3 = data;
  });
  fs.readFile('photos/'+req.query.email+'/photo4.png', 'utf8', (err, data) => {
    if (err) throw err;
    photo4 = data;
  });
  fs.readFile('photos/'+req.query.email+'/photo5.png', 'utf8', (err, data) => {
    if (err) throw err;
    photo5 = data;
  });
  console.log("photo4 :"+ photo4);
  MongoClient.connect(url, function(err, db) {
    assert.equal(null, err);
    console.log("Connected successfully to server");
    // Get the documents collection
    var collection = db.collection('clients');
    // Insert some documents
    collection.find(
      {email : req.query.email}).toArray(function(err, docs){
        if(docs.length == 0)
        {
          console.log(docs);
          console.log(email);
          console.log(token);
          console.log("coco")
          res.send('register.ejs');
        }
        else {
          //    console.log(photo1);
          docs[0].photo1 = photo1;
          docs[0].photo2 = photo2;
          docs[0].photo3 = photo3;
          docs[0].photo4 = photo4;
          docs[0].photo5 = photo5;
          console.log("joshoua");
    //      console.log(docs[0]);
          if(docs[0].like.indexOf(req.session.email) != -1 &&  docs[0].liked.indexOf(req.session.email) != -1)
          {
            docs[0]["match"] = 1;
          }
          else if(docs[0].like.indexOf(req.session.email) == -1 &&  docs[0].liked.indexOf(req.session.email) != -1){
            docs[0]["match"] = 2;
          }
          else if(docs[0].like.indexOf(req.session.email) == -1 &&  docs[0].liked.indexOf(req.session.email) == -1){
            docs[0]["match"] = 3;
          }
          else if(docs[0].like.indexOf(req.session.email) != -1 &&  docs[0].liked.indexOf(req.session.email) == -1){
            docs[0]["match"] = 4;
          }
          console.log(docs[0]);
          res.send(docs);
          console.log("c'estgood");
          //      console.log(docs);
          //    $('.profile-user').append("erhfrthf")
        }
      });

      console.log("gourifob");
      console.log("okokok");
      //db.close();
    });
    console.log("kamikaze");
  });

  router.get('/dodo', function(req, res) {
    var photo1;
    var photo2;
    var photo3;
    var photo4;
    var photo5;
    fs.readFile('photos/'+req.session.email+'/photo1.png', 'utf8', (err, data) => {
      if (err) throw err;
      photo1 = data;
    });
    fs.readFile('photos/'+req.session.email+'/photo2.png', 'utf8', (err, data) => {
      if (err) throw err;
      photo2 = data;
    });
    fs.readFile('photos/'+req.session.email+'/photo3.png', 'utf8', (err, data) => {
      if (err) throw err;
      photo3 = data;
    });
    fs.readFile('photos/'+req.session.email+'/photo4.png', 'utf8', (err, data) => {
      if (err) throw err;
      photo4 = data;
    });
    fs.readFile('photos/'+req.session.email+'/photo5.png', 'utf8', (err, data) => {
      if (err) throw err;
      photo5 = data;
    });
    console.log("photo4 :"+ photo4);
    MongoClient.connect(url, function(err, db) {
      assert.equal(null, err);
      console.log("Connected successfully to server");
      // Get the documents collection
      var collection = db.collection('clients');
      // Insert some documents
      collection.find(
        {email : req.session.email}).toArray(function(err, docs){
          if(docs.length == 0)
          {
            console.log(docs);
            console.log(email);
            console.log(token);
            console.log("coco")
            res.send('register.ejs');
          }
          else {
            //    console.log(photo1);
            docs[0].photo1 = photo1;
            docs[0].photo2 = photo2;
            docs[0].photo3 = photo3;
            docs[0].photo4 = photo4;
            docs[0].photo5 = photo5;
            res.send(docs);
            console.log("c'estgood");
            //      console.log(docs);
            //    $('.profile-user').append("erhfrthf")
          }
        });


        console.log("okokok");
        //db.close();
      });
      console.log("kamikaze");
    });

    router.post('/stock', function(req, res) {
      console.log("todo");
      var base64Data1 = req.param("photo1").replace(/^data:image\/png;base64,/, "");
      var base64Data2 = req.param("photo2").replace(/^data:image\/png;base64,/, "");
      var base64Data3 = req.param("photo3").replace(/^data:image\/png;base64,/, "");
      var base64Data4 = req.param("photo4").replace(/^data:image\/png;base64,/, "");
      var base64Data5 = req.param("photo5").replace(/^data:image\/png;base64,/, "");
      console.log(req.param("photo2"));
      console.log("laterrevaexploser");
      console.log(req.param("photo1"));
      if(req.param("photo1") == '/global/photos/placeholder.png')
      {
        fs.createReadStream("./global/photos/placeholder.png").pipe(fs.createWriteStream("./photos/"+req.session.email+"/photo1.png"));
      }
      else if (req.param("photo1") == "/"+req.session.email+"/photo1.png") {

      }
      else {
        fs.writeFile('photos/'+req.session.email+'/photo1.png', base64Data1, 'base64', function (err) {
          if (err) throw err;
          console.log('It\'s saved!');
        });
      }
      if(req.param("photo2") == '/global/photos/placeholder.png')
      {
        fs.createReadStream("./global/photos/placeholder.png").pipe(fs.createWriteStream("./photos/"+req.session.email+"/photo2.png"));
      }
      else if (req.param("photo2") == "/"+req.session.email+"/photo2.png") {

      }
      else {
        fs.writeFile('photos/'+req.session.email+'/photo2.png', base64Data2, 'base64', function (err) {
          if (err) throw err;
          console.log('It\'s saved!');
        });
      }
      if(req.param("photo3") == '/global/photos/placeholder.png')
      {
        fs.createReadStream("./global/photos/placeholder.png").pipe(fs.createWriteStream("./photos/"+req.session.email+"/photo3.png"));
      }
      else if (req.param("photo3") == "/"+req.session.email+"/photo3.png") {

      }
      else {
        fs.writeFile('photos/'+req.session.email+'/photo3.png', base64Data3, 'base64', function (err) {
          if (err) throw err;
          console.log('It\'s saved!');
        });
      }

      if(req.param("photo4") == '/global/photos/placeholder.png')
      {
        fs.createReadStream("./global/photos/placeholder.png").pipe(fs.createWriteStream("./photos/"+req.session.email+"/photo4.png"));
      }
      else if (req.param("photo4") == "/"+req.session.email+"/photo4.png") {

      }
      else {
        fs.writeFile('photos/'+req.session.email+'/photo4.png', base64Data4, 'base64', function (err) {
          if (err) throw err;
          console.log('It\'s saved!');
        });
      }
      if(req.param("photo5") == '/global/photos/placeholder.png')
      {
        fs.createReadStream("./global/photos/placeholder.png").pipe(fs.createWriteStream("./photos/"+req.session.email+"/photo5.png"));
      }
      else if (req.param("photo5") == "/"+req.session.email+"/photo5.png") {

      }
      else {
        fs.writeFile('photos/'+req.session.email+'/photo5.png', base64Data5, 'base64', function (err) {
          if (err) throw err;
          console.log('It\'s saved!');
        });
      }

      MongoClient.connect(url, function(err, db) {
        assert.equal(null, err);
        console.log("Connected successfully to server");
        // Get the documents collection
        console.log(req.param("sexuality"));
        var collection = db.collection('clients');
        // Insert some documents
        collection.updateOne(
          { "email" : req.session.email },
          { $set: { "email" : req.param("email"), "sex" : req.param("sex"), "age" : req.param("age"), "sexuality" : req.param("sexuality"), "pacinput" : req.param("pacinput"), "bio" : req.param("bio"), "tokenfield" : req.param("tokenfield"), "firstname" : req.param("firstname"), "surname" : req.param("surname")} }
        );

        res.send("ok");
        console.log("okokok");
        if(req.param("email"))
        fs.renameSync('photos/'+req.session.email, 'photos/'+req.param("email"))
        //db.close();
      });
      console.log("comique");
    });

    module.exports = router;
