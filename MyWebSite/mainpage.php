<?php
session_start();
if($_SESSION["newsession"] != "ok")
{
	header('Location: http://localhost:8080/index.php');
}

?>
<!DOCTYPE html>
<html>
<head>
<style>
ul {
    list-style-type: none;
    margin: 0;
    padding: 0;
    overflow: hidden;
    background-color: #333;
}

li {
    float: left;
}

li a {
    display: block;
    color: white;
    text-align: center;
    padding: 14px 16px;
    text-decoration: none;
}

li a:hover:not(.active) {
    background-color: #111;
}

.active {
    background-color: #4CAF50;
}
</style>
</head>
<body>

<ul>
  <li><a href="deconnexion.php">Déconnexion</a></li>
  <!-- <li><a href="#contact">Contact</a></li>
  <li><a href="#about">About</a></li> -->
</ul>
<div>
<div style="padding:5px; float:left; width:800px; margin:auto; border:8px solid #67ab9f; background-color:#b3d8d2; -moz-border-radius:20px; -khtml-border-radius:20px; -webkit-border-radius:20px; border-radius:20px;">
<video id="video"></video>
<button id="startbutton">Prendre une photo</button>
<img class="objet" src="./objet/Bidon.jpg"  alt="photo">
<img class="objets" src="./objet/Bidon2.jpg"  alt="photo">
</div>
<canvas id="canvas"></canvas><br />
</div>
 <footer>

<p>Camagruuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu    by  pitb</p>

</footer>
<!-- <script src="http://ajax.googleapis.com/ajax/libs/jquery/1.8/jquery.min.js"></script> -->
<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.7.2/jquery.min.js"></script>
<script>
  alert("ok");
  $.ajax({
    url : './Photo-montage/exemple-1.png', // Le nom du script a changé, c'est send_mail.php maintenant !

       type : 'POST', // Le type de la requête HTTP, ici devenu POST
       success: function(result){
        console.log(result);
        console.log(typeof(result));
        var image = new Image();
        //var result1 = atob(result);
       // console.log(result);
       // var result = btoa(result);
       // result = encodeURI(result);
        image.src = result;
        console.log(typeof(image));
       // console.log(result);
        document.body.appendChild(image);
        // var mon_image = new Image();
        // width = 320;
        // height = 0;
        // canvas.width = width;
        // canvas.height = height;
        // mon_image.src = result;
       // canvas.getContext('2d').drawImage(mon_image, 0, 0, width, height);
       // context.drawImage(mon_image, 0, 0, 10, 10, 35, 60, 15, 15);
      //  objets3    = document.querySelector('.objets');
     //   objets3.setAttribute('src', result);

     //   canvas.getContext('2d').drawImage(video, 0, 0, width, height);
    }
  });
	var obj;
	 
	(function() {

  var streaming = false,
      video        = document.querySelector('#video'),
      cover        = document.querySelector('#cover'),
      canvas       = document.querySelector('#canvas'),
      photo        = document.querySelector('#photo'),
      startbutton  = document.querySelector('#startbutton'),
      objet  	= document.querySelector('.objet'),
      objets  	= document.querySelector('.objets'),
      width = 320,
      height = 0;
      console.log(objet);
  navigator.getMedia = ( navigator.getUserMedia ||
                         navigator.webkitGetUserMedia ||
                         navigator.mozGetUserMedia ||
                         navigator.msGetUserMedia);

  navigator.getMedia(
    {
      video: true,
      audio: false
    },
     // function giveadress(){
     // 	var id = 2;
     // }
    function(stream) {
      if (navigator.mozGetUserMedia) {
        video.mozSrcObject = stream;
      } else {
        var vendorURL = window.URL || window.webkitURL;
        video.src = vendorURL.createObjectURL(stream);
      }
      video.play();
    },
    function(err) {
      console.log("An error occured! " + err);
    }
  );

  video.addEventListener('canplay', function(ev){
    if (!streaming) {
      height = video.videoHeight / (video.videoWidth/width);
      video.setAttribute('width', width);
      video.setAttribute('height', height);
      canvas.setAttribute('width', width);
      canvas.setAttribute('height', height);
      streaming = true;
    }
  }, false);

  function takepicture() {
    canvas.width = width;
    canvas.height = height;
  //  canvas.drawImage("./objet/Bidon2.jpg");
  //  var data2 = canvas.toDataURL('image/jpg');
    var data1 = { 'photo': canvas.toDataURL('image/jpg'),
				  'image': obj};
	console.log("youpi");
	console.log("youpi1");
    $.ajax({

       url : 'send_photo.php', // Le nom du script a changé, c'est send_mail.php maintenant !

       type : 'POST', // Le type de la requête HTTP, ici devenu POST
       data : data1,
       success: function(result){
       	//alert(result);
     //   canvas.getContext('2d').drawImage(video, 0, 0, width, height);
    }
    }
    );
	// var data1 = canvas.toDataURL('image/png', 0.1);
    //photo.setAttribute('src', data);
   // canvas.getContext('2d').drawImage(video, 0, 0, width, height);
  }
  objet.addEventListener('click', function(ev){
  		obj = "./objet/Bidon.jpg";
      alert();
  ev.preventDefault();
  }, false);
  objets.addEventListener('click', function(ev){
  		obj = "./objet/Bidon2.jpg";
      alert();
  ev.preventDefault();
  }, false);

  startbutton.addEventListener('click', function(ev){
  	if(obj)
  	{
      takepicture();
  	}
  	else
  		alert("veuillez séléctionner une image");
    ev.preventDefault();
  }, false);

})();
</script>

</body>
</html>
