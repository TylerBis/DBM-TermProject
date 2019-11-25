<?php include "../inc/dbinfo.inc" ?>
<html>
<head>
<title>Password Change</title>
<link rel="stylesheet" href="stylesheet.css">
</head>
<body>

<?php
	$username = $_POST["username"];
	$old_password = $_POST["old_password"];
	$new_password = $_POST["new_password"];
	$confirm_new_password = $_POST["confirm_new_password"];

	if ($new_password == $confirm_new_password) {
		$query = "SELECT * FROM dnts.Users WHERE userName='$username' AND password='$old_password'";
		if (mysqli_num_rows(mysqli_query($db,$query)) == 0) {
      printLoggedInNav($username,$password);
      printPasswordChangeTable($username);
      printColoredMsg("Incorrect old password.", "red");
		}
		else {
			$query = "UPDATE dnts.Users SET password='$new_password' WHERE userName='$username'";
			mysqli_query($db,$query);
      printReturnHomeNav();
      printColoredMsg("Password has been changed.", "green");
		}
	}
	else {
    printLoggedInNav($username,$password);
    printPasswordChangeTable($username);
    printColoredMsg("Passwords do not match.", "red");
	}
?>

</body>
</html>
