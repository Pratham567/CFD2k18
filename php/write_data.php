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
$ida = $_GET["id"];
$statusa = $_GET["status"];
echo $id 'and status is ' $statusa ;

$sql = "UPDATE switches SET status=$statusa WHERE id=$ida";

if ($conn->query($sql) === TRUE) {
    echo "Record updated successfully";
} else {
    echo "Error updating record: " . $conn->error;
}


$conn->close();


?>




