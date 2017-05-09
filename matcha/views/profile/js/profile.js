
$('#tokenfield').tokenfield({
  autocomplete: {
    //source: ['red','blue','green','yellow','violet','brown','purple','black','white'],
    //  delay: 100
  },
  showAutocompleteOnFocus: true
});

function previewFile() {

  var file    = document.querySelector('input[type=file]').files[0];
  var reader  = new FileReader();
  reader.addEventListener("load", function () {
    //    preview1.src = reader.result;
    var i = 1;
    while(i < 6)
    {
      console.log(document.querySelector('#oki'+i).src);
      if (document.querySelector('#oki'+i).src == "http://localhost:8080/global/photos/placeholder.png")
      {
        console.log("oulala");
        document.querySelector('#oki'+i).src = reader.result;
        i = 5;
      }
      i++;
    }
    //  preview1.src = reader.result;
    //  $.post('/ya', {'image' : preview.src});
  }, false);

  if (file) {
    reader.readAsDataURL(file);
  }
}
console.log("poilu");
$('#submit').click(function(){
  console.log("houra");
  var firstname = $("#firstname").val();
  var surname = $("#surname").val();
  var email = $("#email").val();
  console.log(email);
  console.log(surname);
  console.log(firstname);
  var sex = $("#sex option:selected").text();
  var sexuality = $("#sexuality option:selected").text();
  var pacinput = $("#pac-input").val();
  var bio = $("#bio").val();
  var tokenfield = $("#tokenfield").val();
  var oki1 = $("#oki1").attr('src');
  var oki2 = $("#oki2").attr('src');
  var oki3 = $("#oki3").attr('src');
  var oki4 = $("#oki4").attr('src');
  var oki5 = $("#oki5").attr('src');
  var data = {
    firstname: firstname,
    surname: surname,
    email: email,
    sex: sex,
    sexuality: sexuality,
    pacinput: pacinput,
    bio: bio,
    tokenfield: tokenfield,
    photo1: oki1,
    photo2: oki2,
    photo3: oki3,
    photo4: oki4,
    photo5: oki5
  }
  $.ajax({
    url : '/profile/stock',
    type : 'GET',
    data : data,
    // dataType : 'html',
    success : function(code_html, statut){
      console.log("toktok");
    },
    error : function(resultat, statut, erreur){
      console.log("pierromoutarde");
    },
  });
});

function deletephoto(arg){
  $('#'+arg).attr('src','/global/photos/placeholder.png');
  // alert(arg);
}

console.log("papamaman");
$.ajax({
  url : '/profile/dodo',
  type : 'GET',
  // dataType : 'html',
  success : function(code_html, statut){
    console.log("toktok");
    console.log(code_html);
    $('.profile-user').append(code_html[0].surname+"  "+code_html[0].firstname);
    $('#firstname').val(code_html[0].firstname);
    $('#surname').val(code_html[0].surname);
    $('#email').val(code_html[0].email);
    $('#sex').val(code_html[0].sex);
    $('#sexuality').val(code_html[0].sexuality);
    $('#pac-input').val(code_html[0].pacinput);
    $('#bio').val(code_html[0].bio);
    //$('#tokenfield').attr("value", code_html[0].tokenfield);
    var tab = code_html[0].tokenfield.split(",");
    console.log("tableau :"+ tab[0]);
    //  $('#tokenfield').tokenfield('createToken', 'purple');
    for(var i= 0; i < tab.length; i++)
    {
      $('#tokenfield').tokenfield('createToken', tab[i]);
    }
    $('#oki1').attr('src', code_html[0].photo1);
    $('#oki2').attr('src', code_html[0].photo2);
    $('#oki3').attr('src', code_html[0].photo3);
    $('#oki4').attr('src', code_html[0].photo4);
    $('#oki5').attr('src', code_html[0].photo5);
    // console.log("debeug1"+code_html[0].photo1);
    // console.log(code_html[0].photo2);
    // console.log(code_html[0].photo3);
    // console.log(code_html[0].photo4);
    // console.log(code_html[0].photo5);


  },
  error : function(resultat, statut, erreur){
    console.log("pierromoutarde");

  },
});

function initMap() {
  var input = document.getElementById('pac-input');
  var autocomplete = new google.maps.places.Autocomplete(input);
}
initMap();
