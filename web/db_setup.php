<?php
	ini_set("display_errors", 1); // .htaccess php.ini httpd.conf
	error_reporting(E_ALL);
	
	echo "DB_SETUP: <br />";
	
	$db_host='localhost';
    $db_user='pupil';
    $db_password='12345';
    $db_name='freedom';
    
    $conn = mysqli_connect($db_host, $db_user, $db_password);
	mysqli_select_db($conn, $db_name);	
	mysqli_query($conn, "DROP TABLE IF EXISTS `_users`;");
	mysqli_query($conn, "CREATE TABLE _users (id INT PRIMARY KEY AUTO_INCREMENT,
		login VARCHAR(255) NOT NULL,
		password varchar(255) NOT NULL,
		nick VARCHAR (255) NOT NULL,
		gender TINYINT(1)
	 );") or die(mysql_error());
	 
	 echo "user OK <br />";
	//mysqli_query($conn, "SET NAMES cp1251");
    //mysqli_close($conn);

?>
