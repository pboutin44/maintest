<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <title>Titre</title>
        <link rel="stylesheet" type="text/css" href="le.css" />
    </head>

    <body>
    <form method="post" action="treatment.php">
       <p>
            <label for="email">Votre email :</label>
           <input type="email" name="email" id="email" />
           <br />
           <label for="pseudo">Votre pseudo :</label>
           <input type="text" name="pseudo" id="pseudo" />
           
           <br />
           <label for="pass">Votre mot de passe :</label>
           <input type="password" name="pass" id="pass" />
           <br />
           <input type="submit" value="Envoyer" />
          
       </p>
    </form>
    
    </body>
</html>