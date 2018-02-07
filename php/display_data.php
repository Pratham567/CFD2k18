<?php
define('base_url', 'http://localhost/');
require("php_serial.class.php"); 


$servername = "localhost";
$username = "root";
$password = "toor";
$dbname = "egrid";
$conn = new mysqli($servername, $username, $password, $dbname);


if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}   
?>

<?php
$id = $_GET["id"];

$sql = "SELECT status, name FROM switches where id=$id";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    // output data of each row
    while($row = $result->fetch_assoc()) {
        echo "status: " . $row["status"]. " - Name: " . $row["name"].  "<br>";
    }
} else {
    echo "0 results";
}


/*$serial = new phpSerial;
$serial->deviceSet("/dev/ttyACM0");
$serial->confBaudRate(115200);
$serial->deviceOpen();
$serial->sendMessage("green");*/

<?php

$comPort = "/dev/ttyACM0"; //The com port address. This is a debian address

$msg = '';

if(isset($_POST["hi"])){

$serial = new phpSerial;

$serial->deviceSet($comPort);

$serial->confBaudRate(9600);

$serial->confParity("none");

$serial->confCharacterLength(8);

$serial->confStopBits(1);

$serial->deviceOpen();

sleep(2); //Unfortunately this is nessesary, arduino requires a 2 second delay in order to receive the message

$serial->sendMessage("Well hello!");

$serial->deviceClose();

$msg = "You message has been sent! WOHOO!";

}

?>



$conn->close();




?>