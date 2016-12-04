<?php
session_start();
//echo($_SESSION['email']);
$tab = scandir("./Photo-montage");
$tabb = array();
$i = 0;
foreach ($tab as $value){
	if(substr_count($value, '.png') > 0)
	{
	//	echo $value;
	//	echo "okokok";
		$tabb[$i] = $value;
		$i = $i + 1;
	} 
}
//var_dump($tabb);
echo json_encode($tabb);
?>