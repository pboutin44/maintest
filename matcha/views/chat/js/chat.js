alert();




$('#send').click(function(){

var myObject = {from : $("#contact2").html(),
                  to : $("#contact").html(),
                message : $("#contenu").val()};
$('.chats').append('<div class="chat chat-left"><div class="chat-body"><div class="chat-content"><p>'+$("#contenu").val()+'</p></div></div></div>')
socket.emit('chat-message', myObject);
$("#contenu").val("");


});
socket.on('chat-mes', function (message) {
   console.log(message);
   alert();
   $('.chats').append('<div class="chat"><div class="chat-body"><div class="chat-content"><p>rffrfrfrfr</p></div></div></div>')
 })
