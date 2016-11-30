<?php

define( 'DB_NAME', 'my_db' );
define( 'DB_USER', 'root' );
define( 'DB_PASSWORD', 'root' );
define( 'DB_HOST', 'localhost' );
define( 'DB_TABLE', 'client2' );
$connexion = new PDO("mysql:host=".DB_HOST.";dbname=".DB_NAME, DB_USER, DB_PASSWORD);

$email = $_POST['email'];

$stmt = $connexion->prepare("SELECT pass,actif,cle FROM client2 WHERE email='".$email."'");
if($stmt->execute(array(':email' => $email)) && $row = $stmt->fetch())
  {
  	$cle = $row['cle'];
  	echo "un email vous a été envoyé afin de réinitialiser votre mot de passe";
		$destinataire = $email;
		$sujet = "Réinitialisation de votre mot de passe" ;
		$entete = "From: inscription@votresite.com" ;
		 
		// Le lien d'activation est composé du login(log) et de la clé(cle)
		$message = 'Bienvenue sur camagru,
		 
		Pour activer votre compte, veuillez cliquer sur le lien ci dessous
		ou copier/coller dans votre navigateur internet.
		 
		http://localhost:8080/password2.php?email='.urlencode($email).'&cle='.urlencode($cle).'
		 
		 
		---------------
		Ceci est un mail automatique, Merci de ne pas y répondre.';
		 
		 
		mail($destinataire, $sujet, $message, $entete);
  }
  else
  {
  	echo ("adresse mail introuvable");
  }




?>