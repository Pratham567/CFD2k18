<?php
define('base_url', 'http://localhost/');


$servername = "localhost";
$username = "root";
$password = "toor";
$dbname = "egrid";
$conn = new mysqli($servername, $username, $password, $dbname);


if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}   ?>


<!DOCTYPE html>
<html>
<body>
fsfdffg
<?php
echo "My first PHP script!1";
?>


<?php
$var1 = $_GET["a"];
echo $var1;



$sql = "UPDATE switches SET name=$var1 WHERE id=2";

if ($conn->query($sql) === TRUE) {
    echo "Record updated successfully";
} else {
    echo "Error updating record: " . $conn->error;
}






$conn->close();


?>
<?php  



?>
</body>
</html>