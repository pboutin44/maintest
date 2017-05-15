function ImageExist(url)
{
   var img = new Image();
   img.src = url;
   return img.height != 0;
}

$.ajax({
  url : '/discover/all_profil',
  type : 'GET',
  // dataType : 'html',
  success : function(code_html, statut){
    console.log("toktok");
    console.log(code_html);
    console.log(code_html.mine);
    for(var i= 0; i < code_html.length - 1; i++)
    {

    //  console.log(ImageExist("/"+code_html[i].email+"/photo1.png"));
        // if(ImageExist("/"+code_html[i].email+"/photo1.png") == true)
        // {
        console.log(code_html[i].email);
        console.log('DETER');
        console.log(code_html[code_html.length - 1]);
        console.log('DETER2');
        if(code_html[i].email != code_html[code_html.length - 1])
        {
         $('#main').append('<div class="col-lg-3 col-md-6"><div class="widget widget-shadow"><div class="widget-header bg-green-600 padding-30 white"><a class="avatar avatar-100" onclick="mini_profil(`'+code_html[i].email+'`);" img-bordered bg-white pull-left margin-right-20" href="javascript:void(0)"><img src= "/'+code_html[i].email+'/photo1.png" alt=""></a><div class="vertical-align height-100 text-truncate"><div class="vertical-align-middle"><div class="font-size-20 margin-bottom-5 text-truncate">'+code_html[i].firstname+' '+code_html[i].surname+'</div><button type="button" id="id" onclick="like(`'+code_html[i].email+'`);" class="btn btn-outline">Like</button>  <button type="button" id="id" onclick="Chat(`'+code_html[i].email+'`);" class="btn btn-outline">Chat</button></div></div></div></div></div>');
       }
    }
  },
  error : function(resultat, statut, erreur){
    console.log("pierromoutarde");
  },
});
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
function mini_profil(email){
  //alert(email);
  $("#main").empty();
  // $.get("/user_profil", function(data) {
  //   $("#main").append(data);
    $.ajax({
      url : "/user_profil",
      type : 'GET',
      data : {'email' : email},
      success : function(code_html, statut){
        console.log("pigeon");
        console.log(code_html);
        console.log("pigeon2");
        $("#main").append(code_html);
        //console.log(code_html);
      }
    })
  // });
}
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
// $("#site-navbar-collapse").click(function(){
//   alert();
// });
