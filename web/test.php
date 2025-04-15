<?php
	session_start();
	
	// enable php errors
	ini_set("display_errors", 1);
	error_reporting(E_ALL);
	
    $db_host='localhost';
    $db_name='freedom';
    $db_user='pupil';
    $db_password='12345';
    
	$conn = mysqli_connect($db_host, $db_user,$db_password);
	mysqli_select_db($conn, $db_name) or die(mysql_error());
	mysqli_query($conn, "SET NAMES cp1251");
		// mysqli_query do here
	mysqli_close($conn);


	function SafeString($str, $to_utf8=true)
	{
		//$str=strip_tags($str);
		$srt=trim($str);
		$var=  mysql_real_escape_string($str);
		$var= stripcslashes($var);
	//return utf8_encode($var);
		//$var=htmlentities($var);
		return $var;
	}
	
	// HTTP: GET and POST requests
	if($_GET['act'] == 'exit')
	{
	   $_SESSION['admin'] = 0;
	}
	
	
	$result = mysql_query("SELECT id, name FROM page ORDER by numer ASC") or die(mysql_error());

	while ($row1 = mysql_fetch_assoc($result)) {
		$head_links[$row1['id']] = $row1['name'];
	}

	echo ("Hello, World!");
?>
