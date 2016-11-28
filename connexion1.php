<?php
define( 'DB_NAME', 'my_db' );
define( 'DB_USER', 'root' );
define( 'DB_PASSWORD', 'root' );
define( 'DB_HOST', 'localhost' );
define( 'DB_TABLE', 'client2' );
$connexion = new PDO("mysql:host=".DB_HOST.";dbname=".DB_NAME, DB_USER, DB_PASSWORD);

$email = $_POST['email'];
$pass = hash('whirlpool', $_POST['pass']);

$stmt = $connexion->prepare("SELECT pass,actif FROM client2 WHERE email='".$email."'");
if($stmt->execute(array(':email' => $email)) && $row = $stmt->fetch())
  {
    $passbdd = $row['pass'];	// Récupération de la clé
    $actif = $row['actif']; // $actif contiendra alors 0 ou 1
 //   echo"okk";
  }
 // echo"kkkkooookkk";
  if($actif == 1 && $pass == $passbdd)
  {
  //	echo"cacao";
//  	echo"hello";
  	session_start();
  	$_SESSION["newsession"]="ok";
  	$_SESSION["email"]=$email;
  	header('Location: http://localhost:8080/mainpage.php');

  }
  else
  {
  	echo("votre compte n'est pas actif ou votre mot de passe est érroné ou votre compte n'existe pas.");
  }
//   echo($passbdd);
// echo($actif);
// echo "string";