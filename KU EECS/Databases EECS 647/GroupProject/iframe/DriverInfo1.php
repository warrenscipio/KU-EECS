<?php
$servername = "mysql.eecs.ku.edu";
session_start();
//$password = $_POST["pass"];
//$username = $_POST["user"];
$password = "Password123!";
$username = "gcastro";

$dbname = "gcastro";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
echo "<meta http-equiv='Content-Type' content='text/html; charset=iso-8859-1' />
<link rel='stylesheet' href='../styles/style.css' type='text/css' />
<body><div id='container' >


    <div id='window' >

        <h1 align='center' class='triangle-right' >Edit Information</h1>

        <hr>";


echo "";




$sql = 'UPDATE DRIVER SET AVAILABILITY = '.$_POST["availability"].', DLATITUDE = '.$_POST["latitude"].', DLONGITUDE = '.$_POST["longitude"]. 'WHERE PASSWORD = "'.$_SESSION["genpass"].'" AND DUSERNAME = "'.$_SESSION["genuser"].'"';

$result = $conn->query($sql);


if ($result === TRUE) {
     // output data of each row
     header('Location: DriverInfo.php');
         
} else {
	echo $_POST["availability"];
	echo $_POST["latitude"];
	echo $_POST["longitude"];
     echo "0 results";
}



echo "</body>
</html>";


?>