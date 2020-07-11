<?php

/* http://test.phrodrigo.com.ar/medicion.php?dispositivo=751489&humedad=1 */

$disp=$_GET['dispositivo'];
$humedad=$_GET['humedad'];

if(isset($disp) && intval($disp) 
	&& isset($humedad) && intval($humedad)) {
		
	$servername = "localhost";
$database = "u397631310_phr";
$username = "u397631310_jg93";
$password = "IOT1234";

// Create connection

$conn = mysqli_connect($servername, $username, $password, $database);

// Check connection

if (!$conn) {

    die("Connection failed: " . mysqli_connect_error());

}

	$sql = "INSERT INTO mediciones(dispositivo,humedad) VALUES (" . $disp . "," . $humedad . ")";

if (mysqli_query($conn, $sql)) {
      echo "New record created successfully";
} else {
      echo "Error: " . $sql . "<br>" . mysqli_error($conn);
}
mysqli_close($conn);

}
?>