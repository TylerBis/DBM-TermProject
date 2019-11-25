<?php // Database Connection

define('DB_SERVER', 'dnts-db-1.ci9vn2h0fxjz.us-east-2.rds.amazonaws.com');
define('DB_USERNAME', 'myadmin');
define('DB_PASSWORD', 'Iamagenius1');
define('DB_DATABASE', 'dnts');
$db = mysqli_connect(DB_SERVER,DB_USERNAME,DB_PASSWORD,DB_DATABASE);

?>

<?php

  function printHomePage() {
    $primary_color = "rgb(0, 73, 199)";
    $secondary_color = "rgb(37, 182, 245)";
    print "<table style='margin: 0px; padding: 0px;'>";
    print "<tr style='background-color: $primary_color; margin: 0px;'><th><h1 style='color: $secondary_color;'>Movie Soundtrack Search</h1></th></tr>";
    print "</table>";
    print "<table>";
    print "<tr><th><h2 style='color: $primary_color;'>Login</h2></th></tr>";
    print "<form action=\"login.php\" method=\"POST\">";
    print "<tr><th><input type=\"text\" name=\"username\" value=\"\" placeholder=\"Username\"></th></tr>";
    print "<tr><th><input type=\"password\" name=\"password\" value=\"\"  placeholder=\"Password\"></th></tr>";
    print "<tr><th><input style='font-size: 16px; background-color: $primary_color; color: $secondary_color;' type='submit' name='login' value='Login'></th></tr>";
    print "</form>";
    print "<tr><th></th></tr>";
    print "<tr><th><h5>-or-</h5></th></tr>";
    print "<tr><th></th></tr>";
    print "<tr><th><h2 style='color: $primary_color;'>Create an Account</h2></th></tr>";
    print "<form action='createaccount.php' method='POST'>";
    print "<tr><th><input type='text' name='username' value='' placeholder='Username'></th></tr>";
    print "<tr><th><input type='password' name='password' value='' placeholder='Password'></th></tr>";
    print "<tr><th><input type='password' name='confirm_password' value='' placeholder='Confirm Password'></th></tr>";
    print "<tr><th><input style='font-size: 16px; background-color: $primary_color; color: $secondary_color;' type='submit' name='login' value='Create Account'></th></tr>";
    print "</form>";
    print "</table>";
  }

  function printLoggedInNav($username,$password) {
    $primary_color = "rgb(0, 73, 199)";
    $secondary_color = "rgb(37, 182, 245)";
    print "<table style='background-color: $primary_color;'>";
    print "<form action='modify_account.php' method='POST'>";
    print "<tr><th><span style='width: 40%; color: white;'>User</span><input style='font-size: 16px;' type='text' name='username' value='" . $username . "' readonly></th>";
    print "<input type='hidden' name='password' value='" . $password . "' readonly>";
    print "<th><input style='width: 40%;' type='radio' name='change_account' value='delete_account'><span style='color: $secondary_color;'>Delete Account</span></th>";
    print "<th><input style='width: 40%;' type='radio' name='change_account' value='change_password'><span style='color: $secondary_color;'>Change Password</span></th>";
    print "<th><input style='width: 40%; font-size: 16px; background-color: $secondary_color; color: black;' type='submit' name='submit' value='Submit'></th></tr>";
    print "</form>";
    print "</table>";
  }

  function printLoggedInSearch($username,$password) {
    $primary_color = "rgb(0, 73, 199)";
    $secondary_color = "rgb(37, 182, 245)";
    print "<table>";
    print "<tr><th><h2 style='color: $primary_color;'>Movie Soundtrack Search</h2><br/></th></tr>";
    print "<form action=\"songsearch.php\" method=\"POST\">";
    print "<input type='hidden' name='username' value='$username'>";
    print "<input type='hidden' name='password' value='$password'>";
    print "<tr><th><input type=\"text\" name=\"song_name\" value=\"\" placeholder=\"Type the name of a song\"></th></tr>";
    print "<tr><th><input style='font-size: 16px; background-color: $primary_color; color: $secondary_color;' type=\"submit\" value=\"Search\"></th></tr>";
    print "</form>";
    print "</table>";
  }

  function printPasswordChangeTable($username) {
    $primary_color = "rgb(0, 73, 199)";
    $secondary_color = "rgb(37, 182, 245)";
    print "<table>";
    print "<tr><th><h3 style='color: $primary_color;'>Password Change</h3></th></tr>";
    print "<form action='change_password.php' method='POST'>";
    print "<tr><th><input type='text' name='username' value='$username' readonly></th></tr>";
    print "<tr><th><input type='password' name='old_password' value='' placeholder='Old Password'></th></tr>";
    print "<tr><th><input type='password' name='new_password' value='' placeholder='New Password'></th></tr>";
    print "<tr><th><input type='password' name='confirm_new_password' value='' placeholder='Confirm New Password'></th></tr>";
    print "<tr><th><input style='font-size: 16px; background-color: $primary_color; color: $secondary_color;' type='submit' name='submit' value='Submit'></th></tr>";
    print "</table>";
  }

  function printReturnHomeNav() {
    $primary_color = "rgb(0, 73, 199)";
    $secondary_color = "rgb(37, 182, 245)";
    print "<table style='background-color: $primary_color;'>";
    print "<tr><th><h1><a href='login.html' style='color: $secondary_color;'>Return Home</a></h1></th></tr>";
    print "</table>";
  }

  function printColoredMsg($message, $color) {
    print "<table>";
    print "<tr><th><h4 style='color: $color;'>$message</h4></th></tr>";
    print "</table>";
  }

  function printTable($result, $num_rows) {
    $primary_color = "rgb(0, 73, 199)";
    $secondary_color = "rgb(37, 182, 245)";
    print "<table><caption><h1 style='color: $primary_color;'><b>$num_rows Songs</b></h1></caption>";
    print "<tr>";
    $row = mysqli_fetch_array($result);
    $num_fields = mysqli_num_fields($result);
    $keys = array_keys($row);
    for ($index = 0; $index < $num_fields; $index++)
      print "<th class='list_line' style='color: $primary_color; font-size: 24px;'><b>" . $keys[2 * $index + 1] . "</b></th>";
    print "</tr>";
    for ($row_num = 0; $row_num < $num_rows; $row_num++) {
      print "<tr>";
      $values = array_values($row);
      for ($index = 0; $index < $num_fields; $index++) {
        if ($row_num % 2 == 0) {
          $color = $primary_color;
        }
        else {
          $color = $secondary_color;
        }
        $value = htmlspecialchars($values[2 * $index + 1]);
        print "<th class='list_line' style='color: $color; font-size: 20px;'>" . $value . "</th>";
      }
      print "</tr>";
      $row = mysqli_fetch_array($result);
    }
    print "</table>";
  }

?>
