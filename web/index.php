<?php
	session_start();
	ini_set("display_errors", 1); // .htaccess php.ini httpd.conf
	error_reporting(E_ALL);
		
	$REG_FORM = "SIGNUP:
			<form action = \"signup.php\" method = 'post'>
				Login: <input type = 'text' name = 'login' /> <br />
				Pass: <input type = 'password' name = 'password' /> <br />
				Nick: <input type = 'text' name = 'nick' /> <br />
				Gender: <input type = 'radio' name = 'gender' value = '0' /> M 
						<input type = 'radio' name = 'gender' value = '1' /> F
				<br />
				<input type = 'submit' />
			</form>
			
			SIGNIN:
			<form action = \"signin.php\" method = 'post'>
				Login: <input type = 'text' name = 'login' /> <br />
				Pass: <input type = 'password' name = 'password' /> <br />
				<input type = 'submit' />
			</form>";
			
	$CONTENT = "";
	
	if($_SESSION['user_id'] > 0) {
			$CONTENT = "<a href = 'signout.php'>exit</a>";
	}
	
	else {
			$CONTENT = "SIGNUP:
			<form action = \"signup.php\" method = 'post'>
				Login: <input type = 'text' name = 'login' /> <br />
				Pass: <input type = 'password' name = 'password' /> <br />
				Nick: <input type = 'text' name = 'nick' /> <br />
				Gender: <input type = 'radio' name = 'gender' value = '0' /> M 
						<input type = 'radio' name = 'gender' value = '1' /> F
				<br />
				<input type = 'submit' />
			</form>
			
			SIGNIN:
			<form action = \"signin.php\" method = 'post'>
				Login: <input type = 'text' name = 'login' /> <br />
				Pass: <input type = 'password' name = 'password' /> <br />
				<input type = 'submit' />
			</form>";
	}
	
	echo "
	<html>
		<head></head>
		<body>
			$CONTENT
		</body>
	</html>";
?>
