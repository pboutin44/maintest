
var path = require('path');
var fs = require('fs');
var router = require('express').Router();
var MongoClient = require('mongodb').MongoClient
, assert = require('assert');
var request = require('request');
var Promise = require('promise');


var url = 'mongodb://localhost:27017/myproject';
// var url = require('url');
// var url_parts = url.parse(request.url, true);
// var query = url_parts.query;

router.get('/', function(req, res) {
  console.log("petard");
  console.log(req.session.email);
  console.log("dodos");
  console.log(req.session.email);
  res.render("discover/html/discover.ejs");
});


router.get('/unlike', function(req, res) {
  console.log("lachine");
  console.log(req.session.email);
  //console.log(req.params);
  console.log(req.query.email);
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
          // console.log(docs);
          // console.log(email);
          // console.log(token);
          console.log("coco")
          res.render('register.ejs');
        }
        else {

          //   alert("edokedk");
          collection.update({email : docs[0].email}, {
            $pull:{like : req.query.email}
          });
          // res.render('confirmation.ejs');
        }
      });
      collection.find(
        {email : req.query.email}).toArray(function(err, docs){

          if(docs.length == 0)
          {
            console.log(docs);
            console.log(email);
            console.log(token);
            console.log("coco")
            res.render('register.ejs');
          }
          else {

            //  console.log(docs[0]);
            collection.update({email : docs[0].email}, {
              $addToSet:{liked : req.session.email, notif : "someone unlike you"}
            });


            collection.update({email : docs[0].email}, {
              $pull:{liked : req.session.email}
            });
            // if(docs[0].liked.indexOf(req.session.email) != 0)
            // {
            collection.update({email : docs[0].email}, {
              $inc : {popularity : -1}
            });

            // }
            // res.render('confirmation.ejs');
          }
        });


        console.log("okokok");
        res.send('send');
        //db.close();
      });
      // console.log("petard");
      // console.log(req.session.email);
      // res.render("discover/html/discover.ejs");
    });

    router.get('/like_someonereturn', function(req, res) {
      console.log("letourisme");
      console.log(req.session.email);
      //console.log(req.params);
      console.log(req.query.email);
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
              // console.log(docs);
              // console.log(email);
              // console.log(token);
              console.log("coco")
              res.render('register.ejs');
            }
            else {

              //   alert("edokedk");
              collection.update({email : docs[0].email}, {
                $addToSet:{like : req.query.email}
              });
              // res.render('confirmation.ejs');
            }
          });
          collection.find(
            {email : req.query.email}).toArray(function(err, docs){

              if(docs.length == 0)
              {
                console.log(docs);
                console.log(email);
                console.log(token);
                console.log("coco")
                res.render('register.ejs');
              }
              else {

                console.log(docs[0]);
                collection.update({email : docs[0].email}, {
                  $addToSet:{liked : req.session.email, notif : "someone like you in return"}
                });
                // if(docs[0].liked.indexOf(req.session.email) != 0)
                // {
                collection.update({email : docs[0].email}, {
                  $inc : {popularity : +1}
                });

                // }
                // res.render('confirmation.ejs');
              }
            });

            res.send('send');
            console.log("okokok");
            //db.close();
          });
          // console.log("petard");
          // console.log(req.session.email);
          // res.render("discover/html/discover.ejs");
        });


    router.get('/like_someone', function(req, res) {
      console.log("letourisme");
      console.log(req.session.email);
      //console.log(req.params);
      console.log(req.query.email);
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
              // console.log(docs);
              // console.log(email);
              // console.log(token);
              console.log("coco")
              res.render('register.ejs');
            }
            else {

              //   alert("edokedk");
              collection.update({email : docs[0].email}, {
                $addToSet:{like : req.query.email}
              });
              // res.render('confirmation.ejs');
            }
          });
          collection.find(
            {email : req.query.email}).toArray(function(err, docs){

              if(docs.length == 0)
              {
                console.log(docs);
                console.log(email);
                console.log(token);
                console.log("coco")
                res.render('register.ejs');
              }
              else {

                console.log(docs[0]);
                collection.update({email : docs[0].email}, {
                  $addToSet:{liked : req.session.email, notif : "someone like you"}
                });
                // if(docs[0].liked.indexOf(req.session.email) != 0)
                // {
                collection.update({email : docs[0].email}, {
                  $inc : {popularity : +1}
                });

                // }
                // res.render('confirmation.ejs');
              }
            });

            res.send('send');
            console.log("okokok");
            //db.close();
          });
          // console.log("petard");
          // console.log(req.session.email);
          // res.render("discover/html/discover.ejs");
        });

        router.get('/all_profil', function(req, res) {
          console.log("glace vanille");
          console.log(req.session.email);
          MongoClient.connect(url, function(err, db) {
            assert.equal(null, err);
            console.log("Connected successfully to server");
            // Get the documents collection
            var collection = db.collection('clients');
            // Insert some documents
            collection.find().toArray(function(err, docs){
              //    var activate = docs.param("activate");
              //  docs.mine = req.session.email;
              docs.push({mine : req.session.email});
              console.log("cratere");
              console.log(docs);
              console.log("cratere1");
              res.send(docs)
            });
            //  res.render('mainpage.ejs');
            db.close();
          });
          //   res.send("di");
        });

        router.get('/tags', function(req, res) {
          console.log("glace vanille");
          console.log(req.session.email);
          MongoClient.connect(url, function(err, db) {
            assert.equal(null, err);
            console.log("Connected successfully to server");
            // Get the documents collection
            var collection = db.collection('clients');
            // Insert some documents
            collection.find().toArray(function(err, docs){
              //    var activate = docs.param("activate");
              //  docs.mine = req.session.email;
              console.log("cratere");
              var table = [];
              var i = 0;
              var key;
              var j = 0;
              console.log("1");
              while(j < docs.length)
              {
                if(docs[j].email == req.session.email)
                {
                  key = j;
                }
                j++;
              }
              j = 0;
              if(docs[key].tokenfield)
              {
                var table2 = docs[key].tokenfield.split(",");
                var table3 = [];
                console.log("2");
                while(j < docs.length)
                {
                  table3[j] = 0;
                  j++;
                }
                j = 0;
                console.log("3");
                while (j < table2.length)
                {
                  k = 0;
                  while(k < docs.length)
                  {
                    if(docs[k].tokenfield && docs[k].tokenfield.indexOf(table2[j]) >= 0)
                    {
                      table3[k] = table3[k] + 1;
                    }
                    k++;
                  }
                  j++;
                }
                i = 0;
                console.log("jardinno");
                console.log(table3);
                console.log("4");
                while(i < docs.length)
                {
                  docs[i]["ponderation"] = table3[i];
                  i++;
                }
              }
              i = 0;
              //  console.log(docs);
              console.log("gourou");
              i = 0;
              console.log("4");
              console.log(docs);
              while(i < docs.length)
              {
                if(docs[key].pacinput)
                {
                  if(docs[i].pacinput)
                  {
                    var p = new Promise((resolve, reject) => {
                      var pos1 = encodeURIComponent(docs[i].pacinput);
                      var pos2 = encodeURIComponent(docs[key].pacinput);
                      request('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+pos1+'&destinations='+pos2+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg', function (error, response, body1) {
                        body1 = JSON.parse(body1);
                        resolve(body1.rows[0].elements[0].distance.value);  });
                      });
                      table.push(p);
                    }
                    else
                    {
                      var p = new Promise((resolve, reject) => {
                        //    console.log(docs[i].CurrentPosition+"          "+docs[key].pacinput);
                        var pos1 = encodeURIComponent(docs[i].CurrentPosition);
                        var pos2 = encodeURIComponent(docs[key].pacinput);
                        request('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+pos1+'&destinations='+pos2+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg', function (error, response, body1) {
                          body1 = JSON.parse(body1);
                          //console.log('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+docs[i].CurrentPosition+'&destinations='+docs[key].pacinput+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg');
                          console.log(body1);
                          resolve(body1.rows[0].elements[0].distance.value);  });
                        });
                        table.push(p);
                      }

                    }
                    else {
                      if(docs[i].pacinput)
                      {
                        var p = new Promise((resolve, reject) => {
                          var pos1 = encodeURIComponent(docs[i].pacinput);
                          var pos2 = encodeURIComponent(docs[key].CurrentPosition);
                          request('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+pos1+'&destinations='+pos2+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg', function (error, response, body1) {
                            body1 = JSON.parse(body1);
                            resolve(body1.rows[0].elements[0].distance.value);  });
                          });
                          table.push(p);
                        }
                        else
                        {
                          var p = new Promise((resolve, reject) => {
                            var pos1 = encodeURIComponent(docs[i].CurrentPosition);
                            var pos2 = encodeURIComponent(docs[key].CurrentPosition);
                            request('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+pos1+'&destinations='+pos2+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg', function (error, response, body1) {
                              body1 = JSON.parse(body1);
                              resolve(body1.rows[0].elements[0].distance.value);  });
                            });
                            table.push(p);
                          }

                        }
                        i++;
                      }
                      Promise.all(table).then(values => {

                        console.log(values);
                        var i = 0;
                        while(i < docs.length)
                        {
                          docs[i]["distance"] = values[i];
                          i++;
                        }
                        console.log(docs);
                        docs.sort(function (a, b){
                          if (a.ponderation == b.ponderation)
                          {
                            if(a.distance == b.distance)
                            {
                              return(a.popularity - b.popularity);
                            }

                            return(a.distance - b.distance);
                          }
                          else {
                            return(-(a.ponderation - b.ponderation));
                          }

                        })
                        console.log(docs);
                        docs.push({mine : req.session.email});
                        res.send(docs);


                      }, reason => {
                        console.log("skate");
                        console.log(table);
                        console.log(reason);
                        console.log("destroy");
                      });

                      console.log("cratere1");
                    });
                    //  res.render('mainpage.ejs');
                    db.close();
                  });
                  //   res.send("di");
                });

                router.get('/location', function(req, res) {
                  console.log("glace vanille");
                  console.log(req.session.email);
                  MongoClient.connect(url, function(err, db) {
                    assert.equal(null, err);
                    console.log("Connected successfully to server");
                    // Get the documents collection
                    var collection = db.collection('clients');
                    // Insert some documents
                    collection.find().toArray(function(err, docs){
                      //    var activate = docs.param("activate");
                      //  docs.mine = req.session.email;
                      console.log("cratere");
                      var table = [];
                      var i = 0;
                      var key;
                      var j = 0;
                      console.log("1");
                      while(j < docs.length)
                      {
                        if(docs[j].email == req.session.email)
                        {
                          key = j;
                        }
                        j++;
                      }
                      j = 0;
                      if(docs[key].tokenfield)
                      {
                        var table2 = docs[key].tokenfield.split(",");
                        var table3 = [];
                        console.log("2");
                        while(j < docs.length)
                        {
                          table3[j] = 0;
                          j++;
                        }
                        j = 0;
                        console.log("3");
                        while (j < table2.length)
                        {
                          k = 0;
                          while(k < docs.length)
                          {
                            if(docs[k].tokenfield && docs[k].tokenfield.indexOf(table2[j]) >= 0)
                            {
                              table3[k] = table3[k] + 1;
                            }
                            k++;
                          }
                          j++;
                        }
                        i = 0;
                        console.log("jardinno");
                        console.log(table3);
                        console.log("4");
                        while(i < docs.length)
                        {
                          docs[i]["ponderation"] = table3[i];
                          i++;
                        }
                      }
                      i = 0;
                      //  console.log(docs);
                      console.log("gourou");
                      i = 0;
                      console.log("4");
                      while(i < docs.length)
                      {
                        if(docs[key].pacinput)
                        {
                          if(docs[i].pacinput)
                          {
                            var p = new Promise((resolve, reject) => {
                              var pos1 = encodeURIComponent(docs[i].pacinput);
                              var pos2 = encodeURIComponent(docs[key].pacinput);
                              console.log("lekebab");
                              console.log(pos1);
                              console.log(pos2);
                              request('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+pos1+'&destinations='+pos2+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg', function (error, response, body1) {
                                body1 = JSON.parse(body1);
                                resolve(body1.rows[0].elements[0].distance.value);  });
                              });
                              table.push(p);
                            }
                            else
                            {
                              var p = new Promise((resolve, reject) => {
                                //    console.log(docs[i].CurrentPosition+"          "+docs[key].pacinput);
                                var pos1 = encodeURIComponent(docs[i].CurrentPosition);
                                var pos2 = encodeURIComponent(docs[key].pacinput);
                                request('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+pos1+'&destinations='+pos2+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg', function (error, response, body1) {
                                  body1 = JSON.parse(body1);
                                  //console.log('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+docs[i].CurrentPosition+'&destinations='+docs[key].pacinput+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg');
                                  console.log(body1);
                                  resolve(body1.rows[0].elements[0].distance.value);  });
                                });
                                table.push(p);
                              }

                            }
                            else {
                              if(docs[i].pacinput)
                              {
                                var p = new Promise((resolve, reject) => {
                                  var pos1 = encodeURIComponent(docs[i].pacinput);
                                  var pos2 = encodeURIComponent(docs[key].CurrentPosition);
                                  request('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+pos1+'&destinations='+pos2+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg', function (error, response, body1) {
                                    body1 = JSON.parse(body1);
                                    resolve(body1.rows[0].elements[0].distance.value);  });
                                  });
                                  table.push(p);
                                }
                                else
                                {
                                  var p = new Promise((resolve, reject) => {
                                    console.log('helpbis');
                                    console.log('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+docs[i].CurrentPosition+'&destinations='+docs[key].CurrentPosition+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg');
                                    var pos1 = encodeURIComponent(docs[i].CurrentPosition);
                                    var pos2 = encodeURIComponent(docs[key].CurrentPosition);
                                    request('https://maps.googleapis.com/maps/api/distancematrix/json?origins="'+pos1+'"&destinations="'+pos2+'"&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg', function (error, response, body1) {
                                      body1 = JSON.parse(body1);
                                      console.log("help1");
                                      console.log(body1);
                                      console.log(body1.status);
                                      console.log("help2");
                                      resolve(body1.rows[0].elements[0].distance.value);  });
                                    });
                                    table.push(p);
                                  }

                                }
                                i++;
                              }
                              Promise.all(table).then(values => {

                                console.log(values);
                                var i = 0;
                                while(i < docs.length)
                                {
                                  docs[i]["distance"] = values[i];
                                  i++;
                                }
                                console.log(docs);
                                docs.sort(function (a, b){
                                  if (a.distance == b.distance)
                                  {
                                    if(a.ponderation == b.ponderation)
                                    {
                                      return(a.popularity - b.popularity);
                                    }

                                    return(a.ponderation - b.ponderation);
                                  }
                                  else {
                                    return(a.distance - b.distance);
                                  }

                                })
                                console.log(docs);
                                docs.push({mine : req.session.email});
                                res.send(docs);


                              }, reason => {
                                console.log("skate");
                                console.log(table);
                                console.log(reason);
                                console.log("destroy");
                              });

                              console.log("cratere1");
                            });
                            //  res.render('mainpage.ejs');
                            db.close();
                          });
                          //   res.send("di");
                        });


                        router.get('/popularity', function(req, res) {
                          console.log("glace vanille");
                          console.log(req.session.email);
                          MongoClient.connect(url, function(err, db) {
                            assert.equal(null, err);
                            console.log("Connected successfully to server");
                            // Get the documents collection
                            var collection = db.collection('clients');
                            // Insert some documents
                            collection.find().toArray(function(err, docs){
                              //    var activate = docs.param("activate");
                              //  docs.mine = req.session.email;
                              console.log("cratere");
                              var table = [];
                              var i = 0;
                              var key;
                              var j = 0;
                              console.log("1");
                              while(j < docs.length)
                              {
                                if(docs[j].email == req.session.email)
                                {
                                  key = j;
                                }
                                j++;
                              }
                              j = 0;
                              if(docs[key].tokenfield)
                              {
                                var table2 = docs[key].tokenfield.split(",");
                                var table3 = [];
                                console.log("2");
                                while(j < docs.length)
                                {
                                  table3[j] = 0;
                                  j++;
                                }
                                j = 0;
                                console.log("3");
                                while (j < table2.length)
                                {
                                  k = 0;
                                  while(k < docs.length)
                                  {
                                    if(docs[k].tokenfield && docs[k].tokenfield.indexOf(table2[j]) >= 0)
                                    {
                                      table3[k] = table3[k] + 1;
                                    }
                                    k++;
                                  }
                                  j++;
                                }
                                i = 0;
                                console.log("jardinno");
                                console.log(table3);
                                console.log("4");
                                while(i < docs.length)
                                {
                                  docs[i]["ponderation"] = table3[i];
                                  i++;
                                }
                              }
                              i = 0;
                              //  console.log(docs);
                              console.log("gourou");
                              i = 0;
                              console.log("4");
                              while(i < docs.length)
                              {
                                if(docs[key].pacinput)
                                {
                                  if(docs[i].pacinput)
                                  {
                                    var p = new Promise((resolve, reject) => {
                                      console.log('helllllps');
                                      console.log('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+pos1+'&destinations='+pos2+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg');

                                      var pos1 = encodeURIComponent(docs[i].pacinput);
                                      var pos2 = encodeURIComponent(docs[key].pacinput);
                                      request('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+pos1+'&destinations='+pos2+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg', function (error, response, body1) {
                                        body1 = JSON.parse(body1);
                                        console.log("aubergine");
                                        console.log(body1);
                                        resolve(body1.rows[0].elements[0].distance.value);  });
                                      });
                                      table.push(p);
                                    }
                                    else
                                    {
                                      var p = new Promise((resolve, reject) => {
                                        //    console.log(docs[i].CurrentPosition+"          "+docs[key].pacinput);
                                        var pos1 = encodeURIComponent(docs[i].CurrentPosition);
                                        var pos2 = encodeURIComponent(docs[key].pacinput);
                                        console.log("joeblack");
                                        console.log(docs[key]);
                                        console.log(pos1);
                                        console.log(pos2);
                                        console.log("danielblake");
                                        console.log('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+pos1+'&destinations='+pos2+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg');
                                        request('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+pos1+'&destinations='+pos2+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg', function (error, response, body1) {
                                          body1 = JSON.parse(body1);
                                          //console.log('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+docs[i].CurrentPosition+'&destinations='+docs[key].pacinput+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg');
                                          console.log(body1);
                                          resolve(body1.rows[0].elements[0].distance.value);  });
                                        });
                                        table.push(p);
                                      }

                                    }
                                    else {
                                      if(docs[i].pacinput)
                                      {
                                        var p = new Promise((resolve, reject) => {
                                          var pos1 = encodeURIComponent(docs[i].pacinput);
                                          var pos2 = encodeURIComponent(docs[key].CurrentPosition);
                                          request('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+pos1+'&destinations='+pos2+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg', function (error, response, body1) {
                                            body1 = JSON.parse(body1);
                                            resolve(body1.rows[0].elements[0].distance.value);  });
                                          });
                                          table.push(p);
                                        }
                                        else
                                        {
                                          var p = new Promise((resolve, reject) => {
                                            var pos1 = encodeURIComponent(docs[i].CurrentPosition);
                                            var pos2 = encodeURIComponent(docs[key].CurrentPosition);
                                            request('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+pos1+'&destinations='+pos2+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg', function (error, response, body1) {
                                              body1 = JSON.parse(body1);
                                              resolve(body1.rows[0].elements[0].distance.value);  });
                                            });
                                            table.push(p);
                                          }

                                        }
                                        i++;
                                      }
                                      Promise.all(table).then(values => {

                                        console.log(values);
                                        var i = 0;
                                        while(i < docs.length)
                                        {
                                          docs[i]["distance"] = values[i];
                                          i++;
                                        }
                                        console.log(docs);
                                        docs.sort(function (a, b){
                                          if (a.popularity == b.popularity)
                                          {
                                            if(a.distance == b.distance)
                                            {
                                              return(a.ponderation - b.ponderation);
                                            }
                                            else {
                                              return(a.distance - b.distance);
                                            }
                                          }
                                          else {
                                            return(-(a.popularity - b.popularity));
                                          }

                                        })
                                        console.log(docs);
                                        docs.push({mine : req.session.email});
                                        res.send(docs);


                                      }, reason => {
                                        console.log("skate");
                                        console.log(table);
                                        console.log(reason);
                                        console.log("destroy");
                                      });

                                      console.log("cratere1");
                                    });
                                    //  res.render('mainpage.ejs');
                                    db.close();
                                  });
                                  //   res.send("di");
                                });

                                router.get('/age', function(req, res) {
                                  console.log("glace vanille");
                                  console.log(req.session.email);
                                  MongoClient.connect(url, function(err, db) {
                                    assert.equal(null, err);
                                    console.log("Connected successfully to server");
                                    // Get the documents collection
                                    var collection = db.collection('clients');
                                    // Insert some documents
                                    collection.find().toArray(function(err, docs){
                                      //    var activate = docs.param("activate");
                                      //  docs.mine = req.session.email;
                                      console.log("cratere");
                                      var table = [];
                                      var i = 0;
                                      var key;
                                      var j = 0;
                                      console.log("1");

                                      while(j < docs.length)
                                      {
                                        if(docs[j].email == req.session.email)
                                        {
                                          key = j;
                                        }
                                        j++;
                                      }
                                      j = 0;
                                      if(docs[key].tokenfield)
                                      {
                                        var table2 = docs[key].tokenfield.split(",");
                                        var table3 = [];
                                        console.log("2");
                                        while(j < docs.length)
                                        {
                                          table3[j] = 0;
                                          j++;
                                        }
                                        j = 0;
                                        console.log("3");
                                        while (j < table2.length)
                                        {
                                          k = 0;
                                          while(k < docs.length)
                                          {
                                            if(docs[k].tokenfield && docs[k].tokenfield.indexOf(table2[j]) >= 0)
                                            {
                                              table3[k] = table3[k] + 1;
                                            }
                                            k++;
                                          }
                                          j++;
                                        }
                                        i = 0;
                                        console.log("jardinno");
                                        console.log(table3);
                                        console.log("4");
                                        while(i < docs.length)
                                        {
                                          docs[i]["ponderation"] = table3[i];
                                          i++;
                                        }
                                      }
                                      i = 0;
                                      //  console.log(docs);
                                      console.log("gourou");
                                      i = 0;
                                      console.log("4");
                                      while(i < docs.length)
                                      {
                                        if(docs[key].pacinput)
                                        {
                                          if(docs[i].pacinput)
                                          {
                                            var p = new Promise((resolve, reject) => {
                                              var pos1 = encodeURIComponent(docs[i].pacinput);
                                              var pos2 = encodeURIComponent(docs[key].pacinput);
                                              request('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+pos1+'&destinations='+pos2+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg', function (error, response, body1) {
                                                body1 = JSON.parse(body1);
                                                resolve(body1.rows[0].elements[0].distance.value);  });
                                              });
                                              table.push(p);
                                            }
                                            else
                                            {
                                              var p = new Promise((resolve, reject) => {
                                                //    console.log(docs[i].CurrentPosition+"          "+docs[key].pacinput);
                                                var pos1 = encodeURIComponent(docs[i].CurrentPosition);
                                                var pos2 = encodeURIComponent(docs[key].pacinput);
                                                request('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+pos1+'&destinations='+pos2+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg', function (error, response, body1) {
                                                  body1 = JSON.parse(body1);
                                                  //console.log('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+docs[i].CurrentPosition+'&destinations='+docs[key].pacinput+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg');
                                                  console.log(body1);
                                                  resolve(body1.rows[0].elements[0].distance.value);  });
                                                });
                                                table.push(p);
                                              }

                                            }
                                            else {
                                              if(docs[i].pacinput)
                                              {
                                                var p = new Promise((resolve, reject) => {
                                                  var pos1 = encodeURIComponent(docs[i].pacinput);
                                                  var pos2 = encodeURIComponent(docs[key].CurrentPosition);
                                                  request('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+pos1+'&destinations='+pos2+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg', function (error, response, body1) {
                                                    body1 = JSON.parse(body1);
                                                    resolve(body1.rows[0].elements[0].distance.value);  });
                                                  });
                                                  table.push(p);
                                                }
                                                else
                                                {
                                                  var p = new Promise((resolve, reject) => {
                                                    var pos1 = encodeURIComponent(docs[i].CurrentPosition);
                                                    var pos2 = encodeURIComponent(docs[key].CurrentPosition);
                                                    request('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+pos1+'&destinations='+pos2+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg', function (error, response, body1) {
                                                      body1 = JSON.parse(body1);
                                                      resolve(body1.rows[0].elements[0].distance.value);  });
                                                    });
                                                    table.push(p);
                                                  }

                                                }
                                                i++;
                                              }
                                              Promise.all(table).then(values => {

                                                console.log(values);
                                                var i = 0;
                                                while(i < docs.length)
                                                {
                                                  docs[i]["distance"] = values[i];
                                                  i++;
                                                }
                                                console.log(docs);
                                                docs.sort(function (a, b){
                                                  if (a.age == b.age)
                                                  {
                                                    if(a.location == b.location)
                                                    {
                                                      return(a.ponderation - b.ponderation);
                                                    }
                                                    else {
                                                      return(a.location - b.location);
                                                    }
                                                  }
                                                  else {
                                                    return(a.age - b.age);
                                                  }

                                                })
                                                console.log(docs);
                                                docs.push({mine : req.session.email});
                                                res.send(docs);


                                              }, reason => {
                                                console.log("skate");
                                                console.log(table);
                                                console.log(reason);
                                                console.log("destroy");
                                              });

                                              console.log("cratere1");
                                            });
                                            //  res.render('mainpage.ejs');
                                            db.close();
                                          });
                                          //   res.send("di");
                                        });

                                        module.exports = router;
