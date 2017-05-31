var email1 = $("#photo_profil").attr("src");
console.log(email1);
var email = email1.split("/")[0];
$.ajax({
  url : "/chat/basic",
  type : 'GET',
  //    data : {'email' : email},
  success : function(code_html1, statut){
    console.log("requin");
  //  console.log(code_html);
    console.log("requin2");
    console.log(code_html1);
    console.log("rasbian");
    console.log(email);
    console.log(code_html1);
    //$("#main").append("<b id='contact' style='display : none;'>"+email+"</b><b id='contact2' style='display : none;'>"+code_html1+"</b>");
    setTimeout(function(){
    //do what you need here
    $.ajax({
      url : '/chat/historique',
      type : 'GET',
      data : {'email1' : $("#contact2").html(),
              'email2' : $("#contact").html()},
      success : function(code_html, statut){
        console.log("totoyoyo");
        console.log(code_html);
        console.log("tignous");
        if(code_html[0].dialogue)
        {
          var tab = code_html[0].dialogue.split("*_**");
        }
        else {
          var tab = [];
        }
        console.log(code_html);
        console.log(tab);
        var i = 0;
        while(i < tab.length)
        {
             if(tab[i] == $("#contact").html()){
               $('.chats').append('<div class="chat chat-left"><div class="chat-body"><div class="chat-content"><p>'+tab[i + 1]+'</p></div></div></div>')
             }
             else {
               $('.chats').append('<div class="chat"><div class="chat-body"><div class="chat-content"><p>'+tab[i + 1]+'</p></div></div></div>')
             }
             i = i + 2;
        }

      }
    })
}, 100);

  }
})


$('#send').click(function(){

var myObject = {from : $("#contact2").html(),
                  to : $("#contact").html(),
                message : $("#contenu").val()};
$('.chats').append('<div class="chat chat-left"><div class="chat-body"><div class="chat-content"><p>'+$("#contenu").val()+'</p></div></div></div>')
socket.emit('chat-message', myObject);
$("#contenu").val("");


});


 $(document).ready(function() {
   if (blog == "yo") {
     return(0);
   }
   blog = "yo";
  socket.on('chat-mes', function (message) {
     console.log(message);
     console.log("tambour");
    console.log($("#contact2").html());
    console.log(message.to);
    console.log(message.from);

    if(message.to == $("#contact2").html())
    {
      $.ajax({
        url : '/chat/stock_chat',
        type : 'GET',
        data : {'messageto' : message.to,
                'messagefrom' : message.from,
                'message' : message.message},
        success : function(code_html, statut){
          console.log("toktok");
          console.log(code_html);
        }
      })
      $("#chat").remove();
     $('.chats').append('<div class="chat"><div class="chat-body"><div class="chat-content"><p>'+message.message+'</p></div></div></div>')
    }
   })



 })
