<?php include "../inc/dbinfo.inc"; ?>

<html lang="en">
<head>
<meta charset="utf-8">
<title>Movie Soundtrack Search</title>
<link rel="stylesheet" href="stylesheet.css">
</head>
<body>

<?php
	$song_name = $_POST["song_name"];
  $username = $_POST["username"];
  $password = $_POST["password"];

	if ($song_name != "") {
		trim($song_name);
		$song_name = htmlspecialchars($song_name);
		$search_for = "%$song_name%";
		$query = "SELECT song_title,performed_by FROM dnts.songs WHERE song_title LIKE '$search_for'";
		$result = mysqli_query($db,$query);
		$num_rows = mysqli_num_rows($result);
		if ($num_rows == 0) {
      printLoggedInNav($username,$password);
      printLoggedInSearch($username,$password);
      printColoredMsg("Song not found in any movies.", "red");
    }
		else {
      printLoggedInNav($username,$password);
      printLoggedInSearch($username,$password);
      printTable($result,$num_rows);
		}
	}
	else {
		printLoggedInNav($username,$password);
    printLoggedInSearch($username,$password);
    printColoredMsg("Must type the name of a song.", "red");
	}
?>

</body>
</html>
