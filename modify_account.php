<?php include "../inc/dbinfo.inc"; ?>
<html>
<head>
<title>Account Modification</title>
<link rel="stylesheet" href="stylesheet.css">
</head>
<body>

<?php
	$change_account = $_POST["change_account"];
	$username = $_POST["username"];
	$password = $_POST["password"];

	if ($change_account == "delete_account") {
		$query = "DELETE FROM dnts.Users WHERE userName='$username'";
		mysqli_query($db,$query);
    printReturnHomeNav();
    printColoredMsg("Account has been deleted.", "red");
	}
	else if ($change_account == "change_password") {
    printLoggedInNav($username,$password);
    printPasswordChangeTable($username);
	}
	else {
    printLoggedInNav($username,$password);
    printColoredMsg("No option was chose.", "red");
	}

?>

</body>
</html>
