<?php
define( 'DB_NAME', 'my_db' );
define( 'DB_USER', 'root' );
define( 'DB_PASSWORD', 'root' );
define( 'DB_HOST', 'localhost' );
define( 'DB_TABLE', 'client2' );

$connexion = new PDO("mysql:host=".DB_HOST.";dbname=".DB_NAME, DB_USER, DB_PASSWORD);

$email = $_GET['email'];
$cle = $_GET['cle'];
 
// Récupération de la clé correspondant au $login dans la base de données
$stmt = $connexion->prepare("SELECT cle,actif FROM client2 WHERE email='".$email."'");
if($stmt->execute(array(':email' => $email)) && $row = $stmt->fetch())
  {
    $clebdd = $row['cle'];	// Récupération de la clé
    $actif = $row['actif']; // $actif contiendra alors 0 ou 1
  }
  // echo($clebdd);
  // echo("ddd");
  // echo($cle);
 if($clebdd == $cle)
 {
 ?>
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <title>Titre</title>
        <link rel="stylesheet" type="text/css" href="le.css" />
    </head>

    <body>
    <form method="post" action="password3.php">
       <p>
            <label for="pass">Veuillez entrer votre nouveau mot de passe :</label>
           <input type="password" name="pass" id="pass" />
           <br />
           <input type='hidden' name='email' value=<?php echo($email); ?> >
           <input type="submit" value="Envoyer" />
       </p>
    </form>
    
    </body>
</html>


 <?php
 }
 else
 {
 	echo"pasok";
 }
