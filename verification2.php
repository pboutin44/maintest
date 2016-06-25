<?php
session_start();
	if(($_POST["login"]))
		$_SESSION["login"] = $_POST["login"];
	if(($_POST["passwd"]))
		$_SESSION["passwd"] = $_POST["passwd"];
echo 'ok';
$bdd = new PDO('mysql:host=localhost;dbname=camagru;charset=utf8', 'root', 'root');
$req = $bdd->prepare('INSERT INTO client(login, email, password) VALUES(:login, :email, :pwd)');
$req->execute(array(
	"login" => $_SESSION['login'],
	"email" => $_SESSION['email'],
	"pwd" => $_SESSION['passwd']
));
echo 'le membre a bien été ajouté !';

?>