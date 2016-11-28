<?php
define( 'DB_NAME', 'my_db' );
define( 'DB_USER', 'root' );
define( 'DB_PASSWORD', 'root' );
define( 'DB_HOST', 'localhost' );
define( 'DB_TABLE', 'client2' );
$connexion = new PDO("mysql:host=".DB_HOST.";dbname=".DB_NAME, DB_USER, DB_PASSWORD);

$pass = hash('whirlpool', $_POST['pass']);
$email = $_POST['email'];
$stmt = $connexion->prepare("SELECT cle,actif FROM client2 WHERE email='".$email."'");
if($stmt->execute(array(':email' => $email)) && $row = $stmt->fetch())
  {
  	$stmt = $connexion->prepare("UPDATE client2 SET pass= '".$pass."' WHERE email='".$email."'");
	// $stmt->bindParam(':cle', $cle);
	// $stmt->bindParam(':login', $login);
	$stmt->execute();
   echo"nouveau mot de passe enregistré";
  }