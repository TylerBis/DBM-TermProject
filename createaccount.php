<?php include "../inc/dbinfo.inc";?>
<html>
<head>
<title>Create an Account</title>
<link rel="stylesheet" href="stylesheet.css">
</head>
<body>
<?php
	$username = $_POST["username"];
	$password = $_POST["password"];
	$confirm_password = $_POST["confirm_password"];

	if ($password != $confirm_password) {
		$message = "Passwords do not match!";
		$message_color = "red";
	}
	else {
		$query = "INSERT INTO dnts.Users values(NULL,'$username','$password')";
		mysqli_query($db,$query);
		$message = "Account has been created.";
		$message_color = "green";
	}
  printHomePage();
	printColoredMsg($message, $message_color);
?>

</body>
</html>
