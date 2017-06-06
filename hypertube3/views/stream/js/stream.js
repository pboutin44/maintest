var hash = location.pathname.replace(/\/stream\/([a-zA-Z0-9]+).*/, '$1');

function findGetParameter(parameterName) {
    var result = null,
        tmp = [];
    if (!location.search)
      return "";
    location.search
    .substr(1)
        .split("&")
        .forEach(function (item) {
        tmp = item.split("=");
        if (tmp[0] === parameterName) result = decodeURIComponent(tmp[1]);
    });
    return result;
}

var imdb_rating = findGetParameter("avg_rating");
var date = findGetParameter("date");
var identifier = findGetParameter("identifier");
var subject = findGetParameter("subject");
console.log("PARAM|" + imdb_rating +"|PARAM");
$('#avg_rating').append(imdb_rating);
$('#date').append((date.split("T"))[0]);
$('#identifier').append(identifier);
$('#subject').append(subject);

$.getJSON('/torrent/files/'+hash, function(data) {
    //console.log(data);
    $('#listFiles ul').empty();
    for (var i = 0; data.files && i < data.files.length; i++) {
        var li = $('<li></li>');
        var link = '/stream/'+hash+'/'+encodeURIComponent(data.files[i].name);
        li.append('<a href="'+link+'">'+data.files[i].name+'</a>');
        li.find('a').click(function(e) {
            e.preventDefault();
            var li = $(this).parent();
            console.log('click');
            if ($(this).attr('refresh')) {
                $(this).removeAttr('refresh');
                if (li.find('p').length > 0) {
                    p = li.find('p');
                    p.slideUp();
                }
            }
            else {
                $(this).attr('refresh', true);
                var p = $('<p></p>');
                if (li.find('p').length > 0) {
                    p = li.find('p');
                    p.empty();
                }
                else {
                    li.append(p);
                }
                var percent = 0, txt = 'loading...';
                p.append('<button disabled class="btn btn-info btn-loading"><span class="btn-loading-load" style="width:'+percent+'%;"><span class="btn-loading-text">'+txt+'</span></span></button><br>');
                p.hide().slideDown();
            }
        })
        $('#listFiles ul').append(li);
    }
    if (data.files.length == 0) {
        var li = $('<li></li>');
        li.append('<p>No video found in this torrent.</p>');
        $('#listFiles ul').append(li);
    }
});

var video = {};
video.player = videojs('video');
setInterval(()=>{
    if (window.stopInter) {
        return;
    }
    //console.log($('#listFiles ul li a[refresh]').length);
    $('#listFiles ul li a[refresh]').each(function(index, elem) {
        var ln = $(elem).attr('href'), li = $(elem).parent();
        $.getJSON(ln, function(data) {
            //console.log(data, ln);
            var p = $('<p></p>');
            if (li.find('p').length > 0) {
                p = li.find('p');
                p.empty();
            }
            var percent = 0, txt = 'loading...';
            if (data.percent) {
                txt = 'file '+data.percent+'% downloaded';
                percent = data.percent;
            }
            p.append('<button disabled class="btn btn-info btn-loading"><span class="btn-loading-load" style="width:'+percent+'%;"><span class="btn-loading-text">'+txt+'</span></span></button><br>');
            if (data.success) {
                for (let i = 0; i < data.choices.length; i++) {
                    if (i == 0) {
                    }
                    else {
                        //p.append('<br>');
                    }
                    var percent = (data.choices[i].percent ? data.choices[i].percent : 0);
                    p.append('<button href="'+ln+'/webm?res='+data.choices[i].res+'&fps='+data.choices[i].fps+'" class="btn btn-info btn-loading"><span class="btn-loading-load" style="width:'+percent+'%;"><span class="btn-loading-text">'+data.choices[i].res+'p '+data.choices[i].fps+'fps ('+percent+'%)</span></span></button>');
                    //p.append('<a href="'+link+'/webm?res='+data.choices[i].res+'&fps='+data.choices[i].fps+'">'+data.choices[i].res+'p '+data.choices[i].fps+'fps ('+(data.choices[i].percent ? data.choices[i].percent : 0)+'% converted)</a>');
                    //console.log(data.choices[i].secStreamable - 30);
                    if (ln == video.file && video.res == data.choices[i].res && video.fps == data.choices[i].fps) {
                        video.player.duration(data.choices[i].secStreamable);
                        console.log(data.choices[i].secStreamable);
                    }
                    let index = p.find('button').length - 1;
                    $(p.find('button')[index]).click((e) => {
                        e.preventDefault();
                        var href = $(p.find('button')[index]).attr('href');
                        video.file = ln;
                        video.res = data.choices[i].res;
                        video.fps = data.choices[i].fps;
                        console.log(video);
                        video.player.src(href+'&'+new Date().getTime());
                        video.player.play();
                        //$('#video').attr('src', $(this).attr('href'));
                    });
                }
            }
            li.append(p);
        });
    });
}, 1000);

$('#url').submit(function(e) {
    e.preventDefault();
    $.getJSON('/torrent/download/'+encodeURIComponent($('#url input[type=text]').val()), function(data) {
        console.log(data);
        if(data.success) {
            location.href = data.redirect;
        }
        else {
            console.log(data.message);
        }
    });
});

$("#title").click(function() {
    $("body").prepend('<div class="blink"><img class="bounce" style="position: absolute" src="https://img.memesuper.com/5828691878194fbe0dc71047eba6f428_black-girl-meme-confused-wtf-memes-black-girl_683-575.png"></div>');
    $("#spin").addClass('spin');
    $("#blink").addClass('blink jolie');
    $('td').each(function (){
        $(this).css('background-color: transparent');
    });
});
