<?php
session_start();
	if(($_POST["login"]))
		$_SESSION["login"] = $_POST["login"];
	if(($_POST["passwd"]))
		$_SESSION["password"] = $_POST["password"];
	$bdd = new PDO('mysql:host=localhost;dbname=camagru;charset=utf8', 'root', 'root');
	$login = $_POST["login"];
	$passwd = $_POST["password"];
	$rep = $bdd->query("SELECT * FROM client WHERE login='$login'");
	$donnees = $rep->fetch();
	if($donnees['password'] == $passwd)
		header('location: mainpage.php');
	else
		header('location: camagru.php');
?>