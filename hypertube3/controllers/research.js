var path = require('path');
var router = require(path.resolve('./node_modules/express')).Router();
var request = require('request');
var express        =        require("express");
var bodyParser     =        require("body-parser");
var app            =        express();
const cheerioReq = require("cheerio-req");
const imdb = require('imdb-api');
const strsplit = require('strsplit');
var mongodb = require('mongodb');
var mongod_url = 'mongodb://localhost:27017/hypertube';


router.get('/', function(req, res) {
	if (req.session && req.session.pseudo)
	{
		res.sendFile(path.resolve('./views/research/html/research.html'));
	}
	else
	res.redirect('/');
});

router.get('/addviewmovie', function(req, res) {
	if (req.session && req.session.pseudo)
	{
		console.log("popo");
		console.log(req.session);
		var db = req.app.locals.db;
		var collection = db.collection("users");
		//collection.insertOne({hello:'world_no_safe'});
		collection.findOne({"pseudo" : req.session.pseudo}, function(err, user) {
                        if (err) throw err;
                        if (user) {
													var film = user.already_seen+"***"+req.query.identifier;
													collection.update(
											    { pseudo: req.session.pseudo},
											    { $set : {already_seen: film}},
													{ upsert: true }
												);
                        }
                    });
		console.log("debeug");
		console.log(db);
		console.log("debeug2");
		console.log(collection);
	}



});
router.get('/movie_already_seen', function(req, res) {
	var db = req.app.locals.db;
	var collection = db.collection("users");
	collection.findOne({"pseudo" : req.session.pseudo}, function(err, user) {
											if (err) throw err;
											if (user) {
												var film = user.already_seen;
												if(film)
													res.json(film);
												else {
													res.json("0");
												}
											}
									});

});

router.get('/archiveorg', function(req, res) {
	console.log("Archive.org sort");
	var search = req.query.search;
	console.log("debeug1");
	console.log(search);
	var page = req.query.page;
	console.log("debeug2");
	console.log(page);
	var req = "";

	if (search.subject && search.subject != "") {
		req += "subject%3A%28"+ encodeURIComponent(search.subject)+"%29+AND+";
	}

	if (search.title && search.title != "") {
		req += "title%3A%28"+ encodeURIComponent(search.title)+"%29+AND+";
	}

	// if (search.from != "") {
	// 	var date = "date%3A%5B"+from+"-01-01+TO+"+to+"-01-01%5D"
	// } else {
	// 	var date = "date%3A%5B1900-01-01+TO+2016-01-01%5D";
	// }
	console.log("SORT : ", search.sort);
	if (search.sort == 0) {
		sort = "titleSorter";
	}
	else if(search.sort == 1){
		sort = "mediatypeSorter";
	}
	else if(search.sort == 2){
		sort = "date";
	}
	else if(search.sort == 3){
		sort = "avg_rating";
	}
	else if(search.sort == 4){
		sort = "downloads+desc";
	}

	var url = 'https://archive.org/advancedsearch.php?q='+req+'collection%3A%28feature_films%29&fl%5B%5D=avg_rating&fl%5B%5D=date&fl%5B%5D=identifier&fl%5B%5D=subject&fl%5B%5D=title&sort%5B%5D='+sort+'&sort%5B%5D=&rows=50&page=' + page + '&output=json&callback=callback&save=yes';
	console.log ("REQUEST : " + url);
	request(url, function (error, response, body) {
		if (!error && response.statusCode == 200) {
			body = body.substring(9, body.length - 1);
			body = JSON.parse(body);
			body["url"] = url;
			body = JSON.stringify(body);
			res.json(body);
		}
	});

});



function getImdbInfo(movies, cb) {
	console.log("GET IMDB INFO");

	let imdb_promises = [];

	movies.forEach (function (movie) {
		imdb_promises.push(new Promise(function(resolve, reject) {
			imdb.getReq({ name: movie.title }, (err, imdb_res) => {
				if (err) {
					//Set default values there:
					movie.poster = "https://img.isohunt.to/posters/0";
					resolve(movie); // Return movie without imdb infos
				} else {
					imdb_res.torrent = movie.torrent;
					console.log ("IMDB MOVIE INFO : " + JSON.stringify(imdb_res));
					resolve(imdb_res);
				}
			});
		}));
	});

	Promise.all(imdb_promises).then(values => {
		console.log("PROMISES FINISHED : " + values);
		cb(values);
	}, err => {
		console.log(err);
	});
}


function scrap(search, page, cb) {
	var sort_nb = 2;

	if (search.sort == 0) //name
		sort_nb = 2;
	else if (search.sort == 2)//"date"
		sort_nb = 3;

	var url = "http://www.legittorrents.info/index.php?page=torrents&search="+encodeURIComponent(search.title)+"&active=1&category=1&order="+sort_nb+"&by=1&pages=" + page;
	console.log("LEGITTORRENT REQUEST URL : " + url);
	cheerioReq(url, (err, $) => {
		var movies = [];
		$("time").each(function(i, elem) {

			var title = $(this).parent().parent().children().eq(1).children().html();


			var href = $(this).parent().parent().children().eq(1).children().attr('href');
			var href = href.replace("index.php", "download.php");

			var torrent = "http://www.legittorrents.info/" + href + "&f=" + title + ".torrent";

			movies.push({title: title,
				torrent: torrent});
			});
			cb(movies);
		});
	}


	router.get('/legittorrenttest', function(req, res) {

		console.log("Legit torrents scrap | PAGE : " + req.query.page);

		scrap(req.query.search, req.query.page, function(movies) {

			getImdbInfo(movies, function(imdb_info) {
				console.log("SEND TO CLIENT : " + JSON.stringify(imdb_info));
				res.json(JSON.stringify(imdb_info));
			});

		});

	});


	module.exports = router;
