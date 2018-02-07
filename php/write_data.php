<?php
define('base_url', 'http://localhost/');


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
$var_default = 0;
$id_default = 1;

if(!$_GET["status"])
	{$var1 = $var_default;}
else
{
	$var1 = $_GET["status"];
}

if(!$_GET["id"])
	{$id = $id_default;}
else
{
	$id = $_GET["id"];
}

$sql = "UPDATE switches SET status=$var1 WHERE id=$id";

if ($conn->query($sql) === TRUE) {
    echo "Record updated successfully";
} else {
    echo "Error updating record: " . $conn->error;
}





$conn->close();


?>




