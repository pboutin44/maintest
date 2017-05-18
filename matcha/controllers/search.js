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
  // console.log(req.session.email);
  // console.log("dodos");
  // console.log(req.session.email);
  res.render("search/html/search.ejs");
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

      i = 0;
      //  console.log(docs);
      console.log("gourou");
      // while(i < docs.length)
      // {
      //   console.log(docs[i].CurrentPosition);
      //   i++;
      // }
      i = 0;
      console.log("4");
      while(i < docs.length)
      {
        if(docs[key].pacinput)
        {
          if(docs[i].pacinput)
          {
            var p = new Promise((resolve, reject) => {
              request('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+docs[i].pacinput+'&destinations='+docs[key].pacinput+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg', function (error, response, body1) {
                body1 = JSON.parse(body1);
                resolve(body1.rows[0].elements[0].distance.value);  });
              });
              table.push(p);
            }
            else
            {
              var p = new Promise((resolve, reject) => {
            //    console.log(docs[i].CurrentPosition+"          "+docs[key].pacinput);
                request('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+docs[i].CurrentPosition+'&destinations='+docs[key].pacinput+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg', function (error, response, body1) {
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
                request('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+docs[i].pacinput+'&destinations='+docs[key].CurrentPosition+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg', function (error, response, body1) {
                  body1 = JSON.parse(body1);
                  resolve(body1.rows[0].elements[0].distance.value);  });
                });
                table.push(p);
              }
              else
              {
                var p = new Promise((resolve, reject) => {
                  request('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+docs[i].CurrentPosition+'&destinations='+docs[key].CurrentPosition+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg', function (error, response, body1) {
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
        //  console.log(table);

        //   new Promise(
        //     (resolve, reject) => {
        //       docs.sort(function (a, b) {
        //         if(docs[0].pacinput)
        //         {
        //           console.log("3fderf     :   "+i);
        //           if(a.CurrentPosition && b.CurrentPosition)
        //           {
        //           //  console.log("chaman");
        //             request('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+a.CurrentPosition+'&destinations='+docs[0].pacinput+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg', function (error, response, body1) {
        //               // dataType : 'html',
        //               request('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+b.CurrentPosition+'&destinations='+docs[0].pacinput+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg', function (error, response, body2) {
        //                 // dataType : 'html',
        //                 console.log("tavhe");
        //                 body2 = JSON.parse(body2);
        //                 body1 = JSON.parse(body1);
        //
        //             //    console.log(body2.rows[0].elements[0]);
        //               //  console.log(body2.rows[0].elements[0].distance.value);
        //
        //                 if(body1.rows[0].elements[0].distance.value < body2.rows[0].elements[0].distance.value)
        //                   return 1;
        //                 else {
        //                   return -1
        //                 }
        //               });
        //             });
        //           }
        //
        //           else if (a.CurrentPosition && !b.CurrentPosition)
        //           {
        //           //  console.log("chaman1");
        //             request('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+a.CurrentPosition+'&destinations='+docs[0].pacinput+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg', function (error, response, body1) {
        //               // dataType : 'html',
        //               request('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+b.pacinput+'&destinations='+docs[0].pacinput+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg', function (error, response, body2) {
        //                 // dataType : 'html',
        //                 console.log("tae");
        //                 body2 = JSON.parse(body2);
        //                 body1 = JSON.parse(body1);
        //
        //             //    console.log(a);
        //               //  console.log(b);
        //                 // console.log(body2.rows[0].elements[0]);
        //                 // console.log(body2.rows[0].elements[0].distance.value);
        //
        //                 if(body1.rows[0].elements[0].distance.value < body2.rows[0].elements[0].distance.value)
        //                   return 1;
        //                 else {
        //                   return -1
        //                 }
        //               });
        //             });
        //
        //           }
        //           else if (!a.CurrentPosition && b.CurrentPosition) {
        //             // console.log("chaman2");
        //             request('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+a.pacinput+'&destinations='+docs[0].pacinput+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg', function (error, response, body1) {
        //               // dataType : 'html',
        //               request('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+b.CurrentPosition+'&destinations='+docs[0].pacinput+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg', function (error, response, body2) {
        //                 // dataType : 'html',
        //                 console.log("tvhe");
        //                 body2 = JSON.parse(body2);
        //                 body1 = JSON.parse(body1);
        //
        //                 // console.log(body2.rows[0].elements[0]);
        //                 // console.log(body2.rows[0].elements[0].distance.value);
        //
        //                 if(body1.rows[0].elements[0].distance.value < body2.rows[0].elements[0].distance.value)
        //                   return 1;
        //                 else {
        //                   return -1
        //                 }
        //               });
        //             });
        //
        //           }
        //           else if (!a.CurrentPosition && !b.CurrentPosition) {
        //             // console.log("chaman3");
        //             request('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+a.pacinput+'&destinations='+docs[0].pacinput+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg', function (error, response, body1) {
        //               // dataType : 'html',
        //               request('https://maps.googleapis.com/maps/api/distancematrix/json?origins='+b.pacinput+'&destinations='+docs[0].pacinput+'&key=AIzaSyAhMUSGep2jtfHo_jnMhViVj3BDnvwIQEg', function (error, response, body2) {
        //                 // dataType : 'html',
        //                 console.log("tae");
        //                 // console.log(a);
        //                 // console.log("choco");
        //                 // console.log(b);
        //                 body2 = JSON.parse(body2);
        //                 body1 = JSON.parse(body1);
        //
        //                 // console.log(body2.rows[0].elements[0]);
        //                 // console.log(body2.rows[0].elements[0].distance.value);
        //
        //                 if(body1.rows[0].elements[0].distance.value < body2.rows[0].elements[0].distance.value)
        //                   return 1;
        //                 else {
        //                   return -1
        //                 }
        //               });
        //             });
        //           }
        //         }
        //       })
        //       console.log("vacance");
        // //      resolve();
        //     }).then(function(val) {console.log(docs);
        //       console.log("camenber"+val);
        //     //  console.log(docs);
        //       docs.push({mine : req.session.email});
        //       res.send(docs);
        //     });

        // p1.then(function(val) {console.log(docs);
        //   console.log("camenber"+val);
        // //  console.log(docs);
        //   docs.push({mine : req.session.email});
        //   res.send(docs);
        // });
        // p1.catch(
        //   (reason) => {
        //     console.log('Handle rejected promise ('+reason+') here.');
        //   });
        //  console.log(docs);
        console.log("cratere1");
      });
      //  res.render('mainpage.ejs');
      db.close();
    });
    //   res.send("di");
  });
  module.exports = router;
