<?php
$servername = "mysql.eecs.ku.edu";

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
echo "<CENTER><h1>Connected successfully</h1></CENTER>";

$user = $_POST["user"];
$pass = $_POST["pass"];
$name = $_POST["name"];
$lice = $_POST["lice"];
$vtype = $_POST["vehicletype"];
$vplate = $_POST["vehicleplate"];
$vcap = $_POST["vehiclecap"];




$sql = "INSERT INTO DRIVER (DUSERNAME,PASSWORD,NAME,DLICENSE )
VALUES ('$user', '$pass', '$name','$lice')";
$sql1 = "INSERT INTO VEHICLE (PLATE, TYPE, CAPACITY) 
VALUES ('$vplate', '$vtype', '$vcap')";
$sql2 = "INSERT INTO DRIVES (DLICENSE, PLATE)
VALUES ('$lice', '$vplate')";

if ($conn->query($sql) === TRUE) {
    if($conn->query($sql1) === TRUE){
    	if($conn->query($sql2) === TRUE){
    		echo "passed appropriate data";
    	}else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

    }else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

header('Location: DriverLogin.html');

?>
