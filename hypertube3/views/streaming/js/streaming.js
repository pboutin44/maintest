$.ajax({
  url : '/home/streaming',
  type: 'POST',
  data: {imdbld: 'tt1156398'},
  success : function(data) {
    console.log(data);
    data.forEach(function (elem) {
      $("#video").append(
        $("<track label='" + elem.lang + "' kind='subtitles' srclang='" + elem.langShort + "' src='/videos/subtitles/" + elem.fileName + "'>")
      );
    });
  }
});
