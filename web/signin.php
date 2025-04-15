<?php
	session_start();
	$key = "HB)&(*#G$%DSB*#&%";
	ini_set("display_errors", 1); // .htaccess php.ini httpd.conf
	error_reporting(E_ALL);
	
	echo "REGIST SCRIPT: <br />";
	
	$db_host='localhost';
    $db_user='pupil';
    $db_password='12345';
    $db_name='freedom';
    
    $conn = mysqli_connect($db_host, $db_user, $db_password);
	mysqli_select_db($conn, $db_name);
	
	//localhost/signup.php?login=admin&password=12345&nick=vasya&gender=1
	
	$login = $_POST['login'];
	$password = $_POST['password'];	
	$md5_password = md5($key.$password.$key); // !!! HASH
	
	
	/*$res = mysqli_query($conn, "SELECT id FROM _users WHERE login = '$login'");
	
	if(mysqli_num_rows($res) > 0) {
		die("user already exists");
	}*/
	
	/*$res = mysqli_query($conn, "SELECT COUNT(*) AS user_exist FROM _users 
					WHERE login = '$login' AND password = '$md5_password'");

	if(mysqli_fetch_assoc($res)['user_exist'] == 0) {
		die("invalid login");
	}*/
	
	
	$res = mysqli_query($conn, "SELECT id AS id FROM _users 
					WHERE login = '$login' AND password = '$md5_password'");

	if(mysqli_num_rows($res) == 0) {
		die("invalid login");
	}
	
	$_SESSION['user_id'] = mysqli_fetch_assoc($res)['id'];
	 
	 echo "user signin successfull <br />";
	//mysqli_query($conn, "SET NAMES cp1251");
    //mysqli_close($conn);

?>
