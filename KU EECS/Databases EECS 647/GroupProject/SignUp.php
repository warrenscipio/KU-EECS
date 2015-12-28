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

$sql = "INSERT INTO USER (USERNAME,PASSWORD, NAME)
VALUE( '$user' , '$pass', '$name' ) ";


if ($conn->query($sql) === TRUE) {
  //  echo "New record created successfully";
  $sql2 = "INSERT INTO SAVES (USERNAME)
  VALUE( '$user') ";



  if ($conn->query($sql2) === TRUE){
    //echo "worked"
  }else{
    echo "Error: " . $sql2 . "<br>" . $conn->error;
  }

  $sql3 = "INSERT INTO PREFERS (USERNAME)
  VALUE( '$user') ";

  if ($conn->query($sql3) === TRUE){
    //echo "worked"
  }else{
    echo "Error: " . $sql3 . "<br>" . $conn->error;
  }



  $sql4 = "INSERT INTO CLIENT (USERNAME)
  VALUE( '$user') ";

  if ($conn->query($sql4) === TRUE){
    //echo "worked"
  }else{
    echo "Error: " . $sql4 . "<br>" . $conn->error;
  }


} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

include("Login.html");


?>
