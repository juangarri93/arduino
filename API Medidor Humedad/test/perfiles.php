<?php

/* http://test.phrodrigo.com.ar/perfiles.php?id=0*/

$id=$_GET['id'];

$sql = "Select * from Perfiles where userId=$id";

$myArray = getArraySQL($sql);
echo json_encode($myArray);


function connectDB(){

	$server = "localhost";
    $bd = "u397631310_phr";
    $user = "u397631310_jg93";
    $pass = "IOT1234";

    $conexion = mysqli_connect($server, $user, $pass,$bd);

        if($conexion){
            //echo 'La conexion de la base de datos se ha hecho satisfactoriamente';
        }else{
            echo 'Ha sucedido un error inexperado en la conexion de la base de datos';
        }

    return $conexion;
}

function disconnectDB($conexion){

    $close = mysqli_close($conexion);

        if($close){
            //echo 'La desconexion de la base de datos se ha hecho satisfactoriamente';
        }else{
            echo 'Ha sucedido un error inexperado en la desconexion de la base de datos';
        }   

    return $close;
}

function getArraySQL($sql){
    
    //Creamos la conexión con la función anterior
    $conexion = connectDB();

    //generamos la consulta

    mysqli_set_charset($conexion, "utf8"); //formato de datos utf8

    if(!$result = mysqli_query($conexion, $sql)) die(); //si la conexión cancelar programa

    $rawdata = array(); //creamos un array


    //guardamos en un array multidimensional todos los datos de la consulta
    $i=0;

    while($row = mysqli_fetch_assoc($result))
    {
        $rawdata[$i] = $row;
        $i++;
    }

    disconnectDB($conexion); //desconectamos la base de datos

    return $rawdata; //devolvemos el array
}

?>