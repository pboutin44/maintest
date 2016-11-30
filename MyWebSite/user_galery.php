<?php
session_start();
echo($_SESSION['email']);
$tab = scandir("./Photo-montage");
foreach ($tab as $value){
    
}
var_dump($tab);




?>