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

        <h1 align='center' class='triangle-right' >Profile</h1>

        <hr>";


echo "";



$sql = 'SELECT NAME, DLICENSE, AVAILABILITY FROM DRIVER WHERE PASSWORD = "'.$_SESSION["genpass"].'" AND DUSERNAME = "'.$_SESSION["genuser"].'"';

$result = $conn->query($sql);


if ($result->num_rows > 0) {
     // output data of each row
     echo "<ul>";
     while($row = $result->fetch_assoc()) {
         echo "<li> NAME: ". $row["NAME"]."</li>";
         echo "<li> LICENSE#: ".$row["DLICENSE"]."</li>";
         echo "<li> AVAILABILITY:".$row["AVAILABILITY"]."</li>";
         $sql1 = 'SELECT PLATE, TYPE, CAPACITY FROM VEHICLE WHERE PLATE = (SELECT PLATE FROM DRIVES WHERE DLICENSE ='.$row["DLICENSE"].')';
         $result1 = $conn->query($sql1);
         if($result1->num_rows>0){
            while($row1 = $result1->fetch_assoc()){
                echo "<li> PLATE: ". $row1["PLATE"]."</li>";
                echo "<li> TYPE: ". $row1["TYPE"]."</li>";
                echo "<li> CAPACITY: ". $row1["CAPACITY"]."</li>";
            }
         }else{
            echo "0 results";
         }
     }
} else {
     echo "0 results";
}
echo "</ul>";



echo "</body>
</html>";


?>