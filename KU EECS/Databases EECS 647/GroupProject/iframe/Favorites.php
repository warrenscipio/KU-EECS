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

//$loc1 = $_POST["Lat"];
//$loc2 = $_POST["Long"];
//
echo "
<title>EECS 647</title>
<meta http-equiv='Content-Type' content='text/html; charset=iso-8859-1' />
<link rel='stylesheet' href='../styles/style.css' type='text/css' />


<!-- Homepage Specific Elements -->

<body>



<div id='container' >


	<div id='window' >

		<h1 align='center' class='triangle-right' >Favorites</h1>

		<hr>

    <form>
    <b style='color:black'>New Location:</b><br>
    <input type='text' id='Lat' name='Lat'>
    <input type='text'id='Lng' name='Long' >

    </form>
      <button onclick='myFunction()' type='submit' class='float' name='submit'>Update</button>

    <script type='text/javascript' src='http://maps.google.com/maps/api/js?sensor=false'></script>
    <div style='overflow:hidden;height:500px;width:600px;border-radius: 50px;'>
      <div id='gmap_canvas' style='height:400px;width:340px;border-radius: 50px;'></div>
      <style>#gmap_canvas img{max-width:none!important;background:none!important}</style>
      <a class='google-map-code' href='http://www.themecircle.net' id='get-map-data'></a>
    </div>

    <script type='text/javascript'>


    var lat=38.95139080000001;
    var lng=-95.25274769999999;


    function myFunction() {
    var x = document.getElementById('Lat').value;
    var y = document.getElementById('Lng').value;

    lat=x;
    lng=y;
    init_map();

    }


    function init_map(){


      var myOptions = {
        zoom:16,
        center:new google.maps.LatLng(lat,lng)
        ,mapTypeId: google.maps.MapTypeId.ROADMAP};
        map = new google.maps.Map(document.getElementById('gmap_canvas'), myOptions);
        marker = new google.maps.Marker({
          map: map,position: new google.maps.LatLng(lat, lng)});
          infowindow = new google.maps.InfoWindow({content:'<b>Lawrence</b><br/>1520 W 15th St<br/>66046 Lawrence' });
          google.maps.event.addListener(marker, 'click', function(){infowindow.open(map,marker);});}google.maps.event.addDomListener(window, 'load', init_map);


          </script>";



echo $loc1;
echo $loc2;


echo"



</div>
</div>



</body>
</html>";

//var lat = 38.95738080000001;
//var lng = -95.25274769999999;


?>
