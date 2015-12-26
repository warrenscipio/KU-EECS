<?php
session_start();
?>


<html>

<head>
<title>EECS 647</title>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<link rel="stylesheet" href="../styles/style.css" type="text/css" />


<!-- Homepage Specific Elements -->
</head>

<body>



<div id="container" >


	<div id="window" >

		<h1 id="p1" align="center" class="triangle-right" >Current Services</h1>

		<hr>

		<b id="p2" style="color:black"> Where you are needed</b>


		<?php
			$servername = "mysql.eecs.ku.edu";
			$password = "Password123!";
			$username = "gcastro";
			$dbname = "gcastro";
			$conn = new mysqli($servername, $username, $password, $dbname);
			if ($conn->connect_error) {
    			die("Connection failed: " . $conn->connect_error);
			}
			$sql = 'SELECT * FROM VEHICLE WHERE PLATE = (SELECT PLATE FROM DRIVES WHERE DLICENSE = (SELECT DLICENSE FROM DRIVER WHERE PASSWORD = "'.$_SESSION["genpass"].'" AND DUSERNAME = "'.$_SESSION["genuser"].'"))' ;
			$result = $conn->query($sql);
			$capacity = 10;
			$sql1 = '';
			echo '<form action="DriverServices.php" method="post">';
			if($result->num_rows > 0){
				while($row = $result->fetch_assoc()){
					$type = $row["TYPE"];
					$sql1 = 'SELECT * FROM CLIENT WHERE VEHICLETYPEREQ = "'.$type.'"';
					$result1 = $conn->query($sql1);

					if($result1->num_rows > 0){
						while($row1 = $result1->fetch_assoc()){
							$user = $row1["USERNAME"];
							$pilat = $row1["PICKUPLAT"];
							$pilong = $row1["PICKUPLONG"];
							echo '<input type="radio" name="option" value ="'.$user.'">'.$user.'<br>';

						}
					}else{
						echo "ouch1";
					}
				}
			}else{
				echo "ouch";
			}
			echo '<br>';
			echo '<input type="submit" value="Submit"></input>';

			$client = $_POST['option'];

			$licensesql = 'SELECT DLICENSE FROM DRIVER WHERE PASSWORD = "'.$_SESSION["genpass"].'" AND DUSERNAME = "'.$_SESSION["genuser"].'"';

			$res = $conn->query($licensesql);

			if($res->num_rows > 0){
			    while($row = $res->fetch_assoc()){
			        $license = $row['DLICENSE'];
			      //  $sql = 'INSERT INTO PICKSUP VALUES("'.$client.'", "'.$license.'")';

							$sql = 'UPDATE PICKSUP SET DLICENSE= "'.$license.'"
							WHERE USERNAME = "'.$_SESSION["genuser"].'" ';

			        $result = $conn->query($sql);
			        if ($result === TRUE) {
			     // output data of each row

			            $sql1 = 'SELECT * FROM CLIENT WHERE USERNAME = "'.$client.'"';
			            $result1 = $conn->query($sql1);
			            if($result1->num_rows > 0){
			                while($row1 = $result1->fetch_assoc()){
			                    $lat = $row1['PICKUPLAT'];
			                    $long = $row1['PICKUPLONG'];
			                    $dlat = $row1['DESTLAT'];
			                    $dlong = $row1['DESTLONG'];

													echo "<br> You have to pickup ".$client."<br>";
			                    echo ' PickUp Location to Lat: <b id="Lat">'.$lat.'</b> Long: <b id="Lng">'.$long.'</b><br>';
			                    echo ' Destination at Lat: <b id="DLat">'.$dlat.'</b> Long: <b id="DLng">'.$dlong.'</b>';
                          echo "</form>";
                            echo "<form>";
                        echo '<input name="remove" type="submit" value="remove"></input>';
                        echo "<form>";
                        if (isset($_POST['remove'])){
                        
                       $sql4 = 'UPDATE CLIENT SET VEHICLETYPEREQ = NULL 
							WHERE USERNAME = "'.$client.'" ';

			        $result4 = $conn->query($sql4);
			        if ($result4 === TRUE) {
                  
                   }     
                       }

													//echo ' <b id="Lat">'.$lat.'</b> <b id="Lng">'.$long.'</b>';
													//echo ' <b id="DLat">'.$dlat.'</b><b id="DLng">'.$dlong.'</b>';



													echo"<script type='text/javascript' src='http://maps.google.com/maps/api/js?sensor=false'></script>
													<div style='overflow:hidden;height:500px;width:600px;'>
														<div id='gmap_canvas' style='height:400px;width:350px; border-radius: 25px;'></div>
														<style>#gmap_canvas img{max-width:none!important;background:none!important}</style>
														<a class='google-map-code' href='http://www.themecircle.net' id='get-map-data'></a>
													</div>

													<script type='text/javascript'>


													var lat=38.95139080000001;
													var lng=-95.25274769999999;

													var Dlat=38.95139080000001;
													var Dlng=-95.25274769999999;

													var centerlat = 38.95139080000001;
													var centerlng = -95.25274769999999;


													function myFunction() {
													var x = document.getElementById('Lat').innerHTML;
													var y = document.getElementById('Lng').innerHTML;

													var dx = document.getElementById('DLat').innerHTML;
													var dy = document.getElementById('DLng').innerHTML;

													lat=x;
													lng=y;

													Dlat=dx;
													Dlng=dy;


													centerlat = (parseFloat(lat) + parseFloat(Dlat))/parseFloat(2);
												  centerlng = (parseFloat(lng) + parseFloat(Dlng))/parseFloat(2);





													init_map();

													}
													myFunction();


													function init_map(){


														var myOptions = {
															zoom:12,
															center:new google.maps.LatLng(centerlat,centerlng)
															,mapTypeId: google.maps.MapTypeId.ROADMAP};
															map = new google.maps.Map(document.getElementById('gmap_canvas'), myOptions);
															marker = new google.maps.Marker({
																map: map,position: new google.maps.LatLng(lat, lng)});

															marker2 = new google.maps.Marker({
																map: map,position: new google.maps.LatLng(Dlat, Dlng)});

																infowindow = new google.maps.InfoWindow({content:'<b>PICK UP' });
																infowindow2 = new google.maps.InfoWindow({content:'<b>DESTINATION' });
																google.maps.event.addListener(marker, 'click', function(){infowindow.open(map,marker);});
																google.maps.event.addListener(marker2, 'click', function(){infowindow2.open(map,marker2);});

															}google.maps.event.addDomListener(window, 'load', init_map);


																</script>";
                        echo "</form>";
                        echo "<form>";
                        echo '<input type="submit" value="Submit"></input>';
                        echo "<form>"; 

			                }
			            }else{
			                //echo "ouch1";
			            }

			        } else {
			            echo $_POST["availability"];
			            echo $_POST["latitude"];
			            echo $_POST["longitude"];
			 echo "0 results";
			        }
			    }
			}else {
			  //  echo 'ouch';
			}





		?>


	</div>


</div>



</body>
</html>
