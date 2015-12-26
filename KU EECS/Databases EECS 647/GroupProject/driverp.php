<?php
$servername = "mysql.eecs.ku.edu";
$dbname = "gcastro";
$password = "Password123!";
$username = "gcastro";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$user = $_POST["username"];
$pass = $_POST["password"];


$sql = 'SELECT NAME FROM DRIVER WHERE PASSWORD = "'.$pass.'" AND DUSERNAME = "'.$user.'"';
$result = $conn->query($sql);
if($result->num_rows > 0){
    echo "<ul>";
    while($row = $result->fetch_assoc()) {
         echo "<li>NAME: ". $row["NAME"]."</li>";
     }
     session_start();
     $_SESSION['genuser'] = $user;
     $_SESSION['genpass'] = $pass;
     header('Location: Driver.php');
}
echo "</ul>";


?>