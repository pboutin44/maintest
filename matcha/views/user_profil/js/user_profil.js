// $('#tokenfield').tokenfield({
//   autocomplete: {
//     //source: ['red','blue','green','yellow','violet','brown','purple','black','white'],
//     //  delay: 100
//   },
//   showAutocompleteOnFocus: true
// });
//alert($('#email').html());
var email = $('#email').html();
console.log("samara");
console.log(email);
$.ajax({
  url : '/user_profil/information',
  type : 'GET',
  data : {email : email},
  success : function(code_html, statut){
    console.log("toktok");
  //   $("#profile-photo").attr('src', "/"+code_html.email+"/photo1.png")
  // //  console.log(code_html);
  // //  $("#profile-photo").attr('src', '/'+email+'/photo1.png');
   },
  error : function(resultat, erreur){
    console.log("pierromoutarde", resultat.responseText, erreur);
  },
});

$.ajax({
  url : '/profile/bizarre',
  type : 'POST',
  // dataType : 'html',
  success : function(code_html, statut){
    console.log("toktok");
    $("#profile-photo").attr('src', "/"+$('#email').html()+"/photo1.png")
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
console.log("papamaman");
var email = $('#email').html();
$.ajax({
  url : '/profile/dodo2',
  type : 'GET',
  data : {email : email},
  success : function(code_html, statut){

    console.log("toktok");
    console.log(code_html);
    $('.profile-user').append(code_html[0].surname+"  "+code_html[0].firstname);
    $('#firstname').html(code_html[0].firstname);
    $('#surname').html(code_html[0].surname);
    $('#email').html(code_html[0].email);
    $('#sex').html(code_html[0].sex);
    $('#sexuality').html(code_html[0].sexuality);
    $('#pac-input').html(code_html[0].pacinput);
    $('#bio').html(code_html[0].bio);
    $('#tokenfield').attr("value", code_html[0].tokenfield);
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

// function initMap() {
//   var input = document.getElementById('pac-input');
//   var autocomplete = new google.maps.places.Autocomplete(input);
// }
// initMap();
