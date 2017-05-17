
$('#tokenfield').tokenfield({
  autocomplete: {
    //source: ['red','blue','green','yellow','violet','brown','purple','black','white'],
    //  delay: 100
  },
  showAutocompleteOnFocus: true
});


$.ajax({
  url : '/profile/bizarre',
  type : 'POST',
  // dataType : 'html',
  success : function(code_html, statut){
    console.log("toktok");
    $("#profile-photo").attr('src', "/"+code_html.email+"/photo1.png")
  //  console.log(code_html);
  //  $("#profile-photo").attr('src', '/'+email+'/photo1.png');
  },
  error : function(resultat, erreur){
    console.log("pierromoutarde", resultat.responseText, erreur);
  },
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
  var age = $("#age").val();
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
    age: age,
    tokenfield: tokenfield,
    photo1: oki1,
    photo2: oki2,
    photo3: oki3,
    photo4: oki4,
    photo5: oki5
  }
  var dec = window.btoa(oki1);
//  console.log(oki1 );
  console.log(dec);
  $.ajax({
    url : '/profile/stock',
    type : 'POST',
    data : data,
    // dataType : 'html',
    success : function(code_html, statut){
      console.log("toktok");
    },
    error : function(resultat, erreur){
      console.log("pierromoutarde", resultat.responseText, erreur);
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
    $('#age').val(code_html[0].age);
    $('#sexuality').val(code_html[0].sexuality);
    $('#pac-input').val(code_html[0].pacinput);
    $('#bio').val(code_html[0].bio);
    //$('#tokenfield').attr("value", code_html[0].tokenfield);
    if(code_html[0].tokenfield)
    {
      var tab = code_html[0].tokenfield.split(",");
  //  console.log("tableau :"+ tab[0]);
    //  $('#tokenfield').tokenfield('createToken', 'purple');
    for(var i= 0; i < tab.length; i++)
    {
      $('#tokenfield').tokenfield('createToken', tab[i]);
    }
  }
    console.log("tata");
    // console.log(btoa(unescape(encodeURIComponent(code_html[0].photo1))));
    // console.log(btoa(unescape(encodeURIComponent(code_html[0].photo2))));
    // console.log(btoa(unescape(encodeURIComponent(code_html[0].photo3))));
    // console.log(btoa(unescape(encodeURIComponent(code_html[0].photo4))));
    // console.log(btoa(unescape(encodeURIComponent(code_html[0].photo5))));
    if(btoa(unescape(encodeURIComponent(code_html[0].photo1))) != "77+9CWht77+9f++/vRot77+977+96ZWnHu+/ve+/vV1677+9Zw==")
      $('#oki1').attr('src', "/"+code_html[0].email+"/photo1.png");
    else {
      $('#oki1').attr('src', "/global/photos/placeholder.png");
    }
    if(btoa(unescape(encodeURIComponent(code_html[0].photo2))) != "77+9CWht77+9f++/vRot77+977+96ZWnHu+/ve+/vV1677+9Zw==")
      $('#oki2').attr('src', "/"+code_html[0].email+"/photo2.png");
      else {
        $('#oki2').attr('src', "/global/photos/placeholder.png");
      }
    if(btoa(unescape(encodeURIComponent(code_html[0].photo3))) != "77+9CWht77+9f++/vRot77+977+96ZWnHu+/ve+/vV1677+9Zw==")
      $('#oki3').attr('src', "/"+code_html[0].email+"/photo3.png");
      else {
        $('#oki3').attr('src', "/global/photos/placeholder.png");
      }
    if(btoa(unescape(encodeURIComponent(code_html[0].photo4))) != "77+9CWht77+9f++/vRot77+977+96ZWnHu+/ve+/vV1677+9Zw==")
      $('#oki4').attr('src', "/"+code_html[0].email+"/photo4.png");
      else {
        $('#oki4').attr('src', "/global/photos/placeholder.png");
      }
    if(btoa(unescape(encodeURIComponent(code_html[0].photo5))) != "77+9CWht77+9f++/vRot77+977+96ZWnHu+/ve+/vV1677+9Zw==")
      $('#oki5').attr('src', "/"+code_html[0].email+"/photo5.png");
      else {
        $('#oki5').attr('src', "/global/photos/placeholder.png");
      }
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
