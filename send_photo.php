<?php
session_start();
$photo = $_POST['photo'];
$image = $_POST['image'];
//chmod('./Photo-montage/test.jpg', '777');
//$file = fopen('./objet/Bidon.jpg', 'w+');
$file2 = $file;
$lire = imagecreatefromjpeg('./objet/Bidon.jpg');
$parts = explode(',', $photo);
$time = date('h:i:s');;
$data = $parts[1];
$data = base64_decode($data);
$fp = fopen('Photo-montage/'.$_SESSION['email'].$time.'.png', 'w');
fwrite($fp, $data);
fclose($fp);
//$var = file_get_contents($photo);

//fclose($file);
//echo($lire);
// echo(json_encode("slt"));

// $img = base64_encode ( $data )
// file_put_contents('Photo-montage/test1.jpg', 'objet/Bidon.jpg');
//Traitement de l'image source
$source = imagecreatefromjpeg($image);
$largeur_source = imagesx($source);
$hauteur_source = imagesy($source);
//  $fp = fopen('exemple-3.png', 'w');
// fwrite($fp, $source);
// fclose($fp);
// Traitement de l'image destination
$destination = imagecreatefrompng('Photo-montage/'.$_SESSION['email'].$time.'.png');
$largeur_destination = imagesx($destination);
$hauteur_destination = imagesy($destination);
  
// Calcul des coordonnées pour placer l'image source dans l'image de destination
$destination_x = ($largeur_destination - $largeur_source)/2;
$destination_y =  ($hauteur_destination - $hauteur_source)/2;
  
// On place l'image source dans l'image de destination
imagecopymerge($destination, $source, $destination_x, $destination_y, 0, 0, $largeur_source, $hauteur_source, 100);
 
// On affiche l'image de destination
//$fp = fopen('exemple-2.png', 'w');
//fwrite($fp, $destination);
//fclose($fp);
//echo($destination);
 imagejpeg($destination, 'Photo-montage/'.$_SESSION['email'].$time.'.png');
 echo($_SESSION['email']);
// imagedestroy($source);
// imagedestroy($destination);
// $res = json_encode("jenfjenrf")
// echo($res);
?>