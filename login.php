<?php include "../inc/dbinfo.inc"; ?>
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="utf-8">
<title>Movie Sountrack Search Login</title>
<link rel="stylesheet" href="stylesheet.css">
</head>
<body>

<?php

$username = $_POST["username"];
$password = $_POST["password"];

if ($username != "" && $password != "") {
  trim($username);
  trim($password);
  $username = htmlspecialchars($username);
  $password = htmlspecialchars($password);
  $query = "SELECT userName,password FROM dnts.Users WHERE userName='$username' AND password='$password'";
  $result = mysqli_query($db,$query);
  $num_rows = mysqli_num_rows($result);
  if ($num_rows == 0) {
    printHomePage();
    printColoredMsg("Incorrect login information.", "red");
  }
  else {
    printLoggedInNav($username,$password);
    printLoggedInSearch($username,$password);
  }

}
else {
  printHomePage();
  printColoredMsg("Incorrect login information.", "red");
}

?>

</body>
</html>
