var path = require('path')
var router = require('express').Router();
var request = require('request');
var cheerio = require('cheerio');

router.post('/', function(req, res) {
  console.log("REQ BODY : " + JSON.stringify(req.body));
  switch(req.body.videos) {
    case 'popular':
      getPopularVideos();
      break;
    case 'torrent':
      getTorrent(req.body.media_id);
      break;
    default:
      res.json("Hum.. Ca va ?.. Non ?.. Bon bah tant pis, Bye ! ~(\"_\")~");
  }

  function getTorrentFile (url) {
    request(url, function(error, response, html) {
        var torrent;
        if(!error) {
            var $ = cheerio.load(html);
            $('.btn-download').each(function(i, element){
                var data = $(this);
                torrent = data.attr("href");
                console.log("TORRENT : " + torrent);
            })
        }
        res.json(torrent);
    })
  }

  function getTorrent (media_id) {
    url = 'https://isohunt.to/cards/movie/' + media_id + '?sort=seeders';
    request(url, function(error, response, html) {
        var torrent;
        if(!error) {
            var $ = cheerio.load(html);
            $('tr[data-key=0]').filter(function(i, element){
                var path = $(this).find('td.title-row').children().first().attr('href');
                var url = "https://isohunt.to" + path;
                console.log("URL : " + url);
                getTorrentFile(url);
            })
        }
    })
  }

  function getPopularVideos () {
    url = 'https://isohunt.to/torrents/?iht=5';
    request(url, function(error, response, html){
        var scraped = [];
        if(!error){
            var $ = cheerio.load(html);

            $('article').each(function(i, element){
                var data = $(this);

                scraped.push({'title': data.children().first().find('p').html(),
                              'image': data.children().first().children().first().children().first().attr('src')});
                console.log("title : " + scraped[i].title + "|| img : " + scraped[i].image);
            })
        }
        res.json(scraped);
    })



  }

});
router.post('/language', function(req, res) {
	console.log("NESTOR42");
	console.log(typeof(req.session));
	console.log(req.session.language);
	if(req.body.language)
	{
		console.log("1");
		req.session.language = req.body.language;
	}
  console.log("disturb");
  console.log(req.body.language);
	//console.log(re);
	res.send(req.session.language);
	// myProfileLib.updateProfile(req, res, function(data) {
	// 	if (typeof data === 'object')
	// 		res.json(data);
	// 	else
	// 		res.send(data);
	// });
});

router.post('/research', function(req, res) {
  res.send('user ');

	console.log("ijijijij");
});


module.exports = router;
