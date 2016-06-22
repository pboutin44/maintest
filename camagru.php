<?php
session_start();


?>

<!-- <html> -->
	<!-- <head> -->
		<!-- <title>camagru</title> -->
	<!-- </head> -->
<!-- <body> -->
	<!-- camagru <BR /> -->
	<!-- <input type="file" accept="image/*;capture=camera"> -->
	<!-- <input type="file" accept="video/*;capture=camcorder"> -->
	<!-- <input type="file" accept="audio/*;capture=microphone"> -->

<!-- </body> -->
<!-- <script src="test.js"></script> -->
<!-- </html> -->
<html>
<head>
<title>Camagru</title>
</head>

<body>

<div>

<div>
<h1> Camagru <br/> <small> inscription </small></h1>
</div>

<div>
<label for="Email">Email address</label>
<input type="text" class="form-control" name="email" placeholder="Enter email">
</div>

<div>
<label for="Password">Mot de passe</label>
<input type="password" class="form-control" name="password" placeholder="Mot de passe">
<label for="Vpassword">Vérification mot de passe</label>
<input type="password" class="form-control" name="vpassword" placeholder="Vérification mot de passe">
</div>

<br/>
<div>
<button type="button">Envoyer mes informations</button>
</div>

</div>
<from action="camagru.php" method="post">
		Email address : <input type="text" name="email" value="" />
		<br />
		login : <input type="text" name="login" value="" />
		password : <input type="password" name="password" value="" />
		<input type="submit" name="submit" value="OK" />
</from>
</body>
</html>