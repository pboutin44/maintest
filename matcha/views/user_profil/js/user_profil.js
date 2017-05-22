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
    $("#like").attr("onclick", "like("+code_html[0].email+");")
    $("#chat").attr("onclick", "chat("+code_html[0].email+");")
    $("#report").attr("onclick", "report("+code_html[0].email+");")
    $("#blocker").attr("onclick", "block('"+code_html[0].email+"');")
    $('.profile-user').append(code_html[0].surname+"  "+code_html[0].firstname);
    $('#firstname').html(code_html[0].firstname);
    $('#surname').html(code_html[0].surname);
    $('#email').html(code_html[0].email);
    $('#sex').html(code_html[0].sex);
    $('#age').html(code_html[0].age);
    $('#sexuality').html(code_html[0].sexuality);
    $('#pac-input').html(code_html[0].pacinput);
    $('#popularity').html(code_html[0].popularity);
    $('#bio').html(code_html[0].bio);
    $('#LastConnection').html(code_html[0].connection);
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
function like(email){

  $.ajax({
    url : '/discover/like_someone',
    type : 'GET',
    data : {'email' : email},
    success : function(code_html, statut){
      console.log("toktok");
      console.log(code_html);
    }
  })


}
function Chat(email){
  $("#main").empty();
  // $.get("/user_profil", function(data) {
  //   $("#main").append(data);
  $.ajax({
    url : "/chat",
    type : 'GET',
    data : {'email' : email},
    success : function(code_html, statut){
      console.log("requin");
      console.log(code_html);
      console.log("requin2");
      $("#main").append(code_html);
      //console.log(code_html);
    }
  })
}

function report(email){
//  $("#main").empty();
  // $.get("/user_profil", function(data) {
  //   $("#main").append(data);
  $.ajax({
    url : "/user_profil/report",
    type : 'GET',
    data : {'email' : email},
    success : function(code_html, statut){
      // console.log("requin");
      // console.log(code_html);
       console.log("requin2");
      // $("#main").append(code_html);
      //console.log(code_html);
    }
  })
}
function block(email){
//  $("#main").empty();
  // $.get("/user_profil", function(data) {
  //   $("#main").append(data);
  $.ajax({
    url : "/user_profil/block",
    type : 'GET',
    data : {'email' : email},
    success : function(code_html, statut){
      // console.log("requin");
      // console.log(code_html);
       console.log("requin2");
      // $("#main").append(code_html);
      //console.log(code_html);
    }
  })
}


$.ajax({
  url : '/user_profil/maintips',
  type : 'GET',
  success : function(code_html, statut){
    console.log("verifcotcah");
    console.log(code_html[0].flag);
    if(code_html[0].flag == 1)
    {
      $("#like").remove();
      $("#chat").remove();
    }
    var email = $('#email').html();
    if(code_html[0].like.indexOf(email) == -1 || code_html[0].liked.indexOf(email) == -1)
    {
      $("#chat").remove();
    }

  //  console.log($('#oki1').attr('src'));
  //  console.log("/"+code_html[0].email+"/photo1.png");

//    if($('#oki1').attr('src', "/global/photos/placeholder.png");)
  }
})


// function initMap() {
//   var input = document.getElementById('pac-input');
//   var autocomplete = new google.maps.places.Autocomplete(input);
// }
// initMap();
