$('#send').click(function(){

var myObject = {from : $("#contact2").html(),
                  to : $("#contact").html(),
                message : $("#contenu").val()};
$('.chats').append('<div class="chat chat-left"><div class="chat-body"><div class="chat-content"><p>'+$("#contenu").val()+'</p></div></div></div>')
socket.emit('chat-message', myObject);
$("#contenu").val("");


});
$.ajax({
  url : '/chat/historique',
  type : 'GET',
  data : {'email1' : $("#contact2").html(),
          'email2' : $("#contact").html()},
  success : function(code_html, statut){
    console.log("totoyoyo");
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
    if(message.to == $("#contact2").html())
    {
     $('.chats').append('<div class="chat"><div class="chat-body"><div class="chat-content"><p>'+message.message+'</p></div></div></div>')
    }
   })



 })
