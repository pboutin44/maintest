var imdbApi = require('imdb-api');
var imdb = {};

imdb.get = function(title, callback) {
    imdbApi.getReq({ name: title }, (err, movie) => {
        if (!err) {
            callback({success: true, info: movie});
        }
        else {
            callback({success: false, message: 'Imdb error.', error: err});
        }
    });
}

module.exports = imdb;
