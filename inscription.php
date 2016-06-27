<?php
$bdd = new PDO('mysql:host=localhost;charset=utf8', 'root', 'root');
$reponse = $bdd->query('CREATE DATABASE IF NOT EXISTS camagru');
if($reponse)
	$bdd->query('USE camagru');
$table= "client";
$columns = "id INT( 11 ) AUTO_INCREMENT PRIMARY KEY, login VARCHAR(50) NOT NULL, email VARCHAR( 50 ) NOT NULL, password VARCHAR( 250 ) NOT NULL" ;
$createTable = $bdd->exec("CREATE TABLE IF NOT EXISTS $table ($columns)");


?>
<html>
<head>
<title>Camagru</title>
</head>
<body>
<h1> Camagru <br/> <small> s'enregistrer </small></h1>
<br/>
<form action="verification.php" method="post">
		Email address : <input type="text" name="email" value="" />
		<br />
		login : <input type="text" name="login" value="" />
		password : <input type="passwd" name="passwd" value="" />
		<input type="submit" name="submit" value="Envoyer mes informations" />
</body>
</html>