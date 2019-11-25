<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <title>Movie Sountrack Search Login</title>
  </head>
  <body>

    <?php
      $db = mysqli_connect(DB_SERVER,DB_USERNAME,DB_PASSWORD,DB_DATABASE,DB_PORT);
      $query = "select * from dnts.movies where tconst='t0000417'";
      $result = mysqli_query($db,$query);

      print "<b> The query is: </b> " . $query_html . "<br />";
      $num_rows = mysqli_num_rows($result);
      print "<table><caption> <h2> Cars ($num_rows) </h2> </caption>";
      print "<tr align = 'center'>";

      $row = mysqli_fetch_array($result);
      $num_fields = mysqli_num_fields($result);

      // Produce the column labels
      $keys = array_keys($row);
      for ($index = 0; $index < $num_fields; $index++)
          print "<th>" . $keys[$index] . "</th>";
      print "</tr>";

      // Output the values of the fields in the rows
      for ($row_num = 0; $row_num < $num_rows; $row_num++) {
          print "<tr align = 'center'>";
          $values = array_values($row);
          for ($index = 0; $index < $num_fields; $index++){
              $value = htmlspecialchars($values[2 * $index + 1]);
              print "<th>" . $value . "</th> ";
          }
          print "</tr>";
          $row = mysqli_fetch_array($result);
      }
      print "</table>";
    ?>

  </body>
</html>
