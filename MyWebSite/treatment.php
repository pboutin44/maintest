<?php
define( 'DB_NAME', 'my_db' );
define( 'DB_USER', 'root' );
define( 'DB_PASSWORD', 'root' );
define( 'DB_HOST', 'localhost' );
define( 'DB_TABLE', 'client2' );
$pdo = new PDO('mysql:host='.DB_HOST, DB_USER, DB_PASSWORD);
$requete = "CREATE DATABASE IF NOT EXISTS `".DB_NAME."` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci";
$pdo->prepare($requete)->execute();
// connexion à la bdd
$connexion = new PDO("mysql:host=".DB_HOST.";dbname=".DB_NAME, DB_USER, DB_PASSWORD);
 
// on vérifie que la connexion est bonne
if($connexion){
  // echo'okko';
  // echo ($_POST[pseudo]);
  // echo ($_POST[email]);
  // echo ($_POST[pass]);
  // echo('ddij');
  // on créer la requête
  $requete = "CREATE TABLE IF NOT EXISTS `".DB_NAME."`.`".DB_TABLE."` (
        `email` VARCHAR( 255 ) PRIMARY KEY,
        `pseudo` VARCHAR( 255 ) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
        `pass` VARCHAR( 255 ) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
        `cle` VARCHAR( 255 ) ,
        `actif` INT
        );";
 
  // on prépare et on exécute la requête
  $connexion->prepare($requete)->execute();
  $requete = "INSERT INTO client2 VALUES ('".$_POST[email]."', '".$_POST[pseudo]."', '".$_POST[pass]."', 'drijr', '0')";
  $connexion->prepare($requete)->execute();
 // header('Location: http://e3r13p9.42.fr:8080/index.php');
  //echo("le nouvel utilisateur a été enregistré avec succès :)");
  $email = $_POST[email];
$login = $_POST[pseudo];
 
// Génération aléatoire d'une clé
$cle = md5(microtime(TRUE)*100000);
echo('okokkkk');
echo($cle);
 echo($login);
 
// Insertion de la clé dans la base de données (à adapter en INSERT si besoin)
$stmt = $connexion->prepare("UPDATE client2 SET cle= '".$cle."' WHERE pseudo='".$login."'");
// $stmt->bindParam(':cle', $cle);
// $stmt->bindParam(':login', $login);
$stmt->execute();
 
 
// Préparation du mail contenant le lien d'activation
$destinataire = $email;
$sujet = "Activer votre compte" ;
$entete = "From: inscription@votresite.com" ;
 
// Le lien d'activation est composé du login(log) et de la clé(cle)
$message = 'Bienvenue sur camagru,
 
Pour activer votre compte, veuillez cliquer sur le lien ci dessous
ou copier/coller dans votre navigateur internet.
 
http://e3r13p12.42.fr:8080/activation.php?log='.urlencode($login).'&cle='.urlencode($cle).'
 
 
---------------
Ceci est un mail automatique, Merci de ne pas y répondre.';
 
 
mail($destinataire, $sujet, $message, $entete);

  ?>
  <script>
    alert('Afin de finaliser l\'inscription nous vous avons envoyé un mail de confirmation :\)');
  </script>
  <?php

}

?>

<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <title>Titre</title>
        <link rel="stylesheet" type="text/css" href="le.css" />
    </head>

    <body>
    
    </body>
</html>