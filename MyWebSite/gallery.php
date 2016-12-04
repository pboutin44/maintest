<?php
define( 'DB_NAME', 'my_db' );
define( 'DB_USER', 'root' );
define( 'DB_PASSWORD', 'root' );
define( 'DB_HOST', 'localhost' );
define( 'DB_TABLE', 'client2' );
define( 'DB_TABLE1', 'commentary' );
$pdo = new PDO('mysql:host='.DB_HOST, DB_USER, DB_PASSWORD);
// connexion à la bdd
$connexion = new PDO("mysql:host=".DB_HOST.";dbname=".DB_NAME, DB_USER, DB_PASSWORD);
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
  <li><a href="mainpage.php">Home</a></li>
  <!-- <li><a href="#contact">Contact</a></li>
  <li><a href="#about">About</a></li> -->
</ul>
<div id="mainDiv" style="padding:5px;  width:78%; margin-left:auto; margin-right:auto; border:8px solid #67ab9f; background-color:#b3d8d2;-moz-border-radius:20px; -khtml-border-radius:20px; -webkit-border-radius:20px; border-radius:20px;">
</div>
</body>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.7.2/jquery.min.js"></script>
<script>
function test(att)
{
  var person = prompt("Please enter your commentary");
  if (person != null) {
        // document.getElementById("demo").innerHTML =
        // "Hello " + person + "! How are you today?";
        $.ajax({
            url : './ieori.php',
        });
        <?php
        $destinataire = $email;
        $sujet = "Activer votre compte" ;
        $entete = "From: inscription@example.com" ;
         
        // Le lien d'activation est composé du login(log) et de la clé(cle)
        $message = 'Bienvenue sur camagru,
        ---------------
        Ceci est un mail automatique, Merci de ne pas y répondre.';
        mail($destinataire, $sujet, $message, $entete);
        $requete = "INSERT INTO client2 VALUES ('".$_POST[email]."', '".$_POST[pseudo]."', 'drijr', '0')";
        $connexion->prepare($requete)->execute();
        ?>

    }
}
function sidebarGalery()
  {
    $.ajax({
      url : './all_user_galery.php', // Le nom du script a changé, c'est send_mail.php maintenant !

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
          // console.log("pq");
          //  console.log(elem);
          // console.log(typeof(result));
          var image = new Image();
          //var result1 = atob(result);
          // console.log(result);
          // var result = btoa(result);
          // result = encodeURI(result);
          image.setAttribute("id", obj[value]);
          image.setAttribute("onclick", "test('"+obj[value]+"');");
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