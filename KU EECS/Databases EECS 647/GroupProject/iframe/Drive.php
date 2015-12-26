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

/*----------------------DATABASE LOGIN-------------------------------------*/

echo "<title>EECS 647</title>
<meta http-equiv='Content-Type' content='text/html; charset=iso-8859-1' />
<link rel='stylesheet' href='../styles/style.css' type='text/css' />

<!-- Homepage Specific Elements -->


<body>


<div id='container' >


	<div id='window' >

		<h1 align='center' class='triangle-right' >Lets GO!</h1>


		<hr>


		<form action='Drive.php' method='post'>

		  <b style='color:black'>Current Location:</b><br>
		  <input type='text' name='Loc1'>
			<input type='text' name='Loc2'>
			<br>
			<b style='color:black'>Type of vehicle:</b><br>
			<input type='text' name='vehicle'>
			<br>
			<b style='color:black'>Destination:</b><br>
			<input type='text' name='Dest1'>
			<input type='text' name='Dest2'><br><br>

			<button type='submit' class='float' name='submit'>Submit</button>
		</form>


";

$loc1 = $_POST["Loc1"];
$loc2 = $_POST["Loc2"];
$vehicle = $_POST["vehicle"];
$dest1 = $_POST["Dest1"];
$dest2 = $_POST["Dest2"];

if (isset($_POST['submit'])){


	$sql = 'UPDATE CLIENT SET DESTLAT= "'.$dest1.'" , DESTLONG="'.$dest2.'", PICKUPLAT="'.$loc1.'",PICKUPLONG="'.$loc2.'",VEHICLETYPEREQ="'.$vehicle.'"
	WHERE USERNAME = "'.$_SESSION["genuser"].'" ';

	if ($conn->query($sql) === TRUE) {
			echo "<h1>Updated</h1>";
	}


	}



echo "	</div>
</div>

</body>
</html>";


?>
