<?php
session_start();
if($_SESSION["newsession"] != "ok")
{
	header('Location: http://localhost:8080/index.php');
}

?>
<!DOCTYPE html>
<html>
<meta charset="UTF-8">
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
  <li><a href="gallery.php">gallery</a></li>
  <!-- <li><a href="#contact">Contact</a></li>
  <li><a href="#about">About</a></li> -->
</ul>
<div id="mainDiv" style="padding:5px; float:left; width:100%; height: 300px; margin:auto; border:8px solid #67ab9f; background-color:#b3d8d2; -moz-border-radius:20px; -khtml-border-radius:20px; -webkit-border-radius:20px; border-radius:20px;">
</div>
</body>
<script>
function sidebarGalery()
  {
    $.ajax({
      url : './user_galery.php', // Le nom du script a changé, c'est send_mail.php maintenant !

          // Le type de la requête HTTP, ici devenu POST
         success: function(result){
          //console.log(result);
          var obj = JSON.parse(result);
          console.log(obj);
          console.log(obj.lenght);
          for (var value in obj)
          {
            console.log(obj[value]);
          
         // var tab = result.split('"');
        //   console.log("yoko");
          // console.log(tab);
         // var elem = document.getElementById('image');
    //      console.log("pq");
        //  console.log(elem);
          // console.log(typeof(result));
          var image = new Image();
          //var result1 = atob(result);
         // console.log(result);
         // var result = btoa(result);
         // result = encodeURI(result);
           image.src = './Photo-montage/'+obj[value];
          // $(image).text(result);
         //  console.log("yoplait");
         //   console.log(decodeURIComponent(result));
         // // console.log(result);
         // document.getElementById('hop').setAttribute('src',result);
         var elem = document.getElementById('mainDiv');
           elem.appendChild(image);
         }
       }
    });
  }
  sidebarGalery();
  </script>