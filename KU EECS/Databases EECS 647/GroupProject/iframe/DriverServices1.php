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

        <h1 align='center' class='triangle-right' >Current Service</h1>

        <hr>";


echo "";



$client = $_POST['option'];

$licensesql = 'SELECT DLICENSE FROM DRIVER WHERE PASSWORD = "'.$_SESSION["genpass"].'" AND DUSERNAME = "'.$_SESSION["genuser"].'"';

$res = $conn->query($licensesql);

if($res->num_rows > 0){
    while($row = $res->fetch_assoc()){
        $license = $row['DLICENSE'];
        $sql = 'INSERT INTO PICKSUP VALUES("'.$client.'", "'.$license.'")';
        $result = $conn->query($sql);
        if ($result === TRUE) {
     // output data of each row
            echo "<p> You have to pickup ".$client."</p>";
            $sql1 = 'SELECT * FROM CLIENT WHERE USERNAME = "'.$client.'"';
            $result1 = $conn->query($sql1);
            if($result1->num_rows > 0){
                while($row1 = $result1->fetch_assoc()){
                    $lat = $row1['PICKUPLAT'];
                    $long = $row1['PICKUPLONG'];
                    $dlat = $row1['DESTLAT'];
                    $dlong = $row1['DESTLONG'];

                    echo '<p> Head to Lat: '.$lat.' Long: '.$long.'</p>';
                    echo '<p> Drop at Lat: '.$dlat.' Long: '.$dlong.'</p>';

                  echo  "<form action= 'DriverServices1.php' method='post' >
                  <button type='submit' class='float' name='submit'>On The Way</button>
                  </form>";


                }
            }else{
                echo "ouch1";
            }

        } else {
            echo $_POST["availability"];
            echo $_POST["latitude"];
            echo $_POST["longitude"];
 echo "0 results";
        }
    }
}else {
    echo 'ouch';
}


if (isset($_POST['submit'])){
  $sql2 = 'DELETE FROM PICKSUP WHERE USERNAME = "'.$client.'"';
  $result2 = $conn->query($sql2);
  if ($result2 === TRUE) {
    echo "DELETED";
    echo $client;

  }



}








echo "</body>
</html>";


?>
