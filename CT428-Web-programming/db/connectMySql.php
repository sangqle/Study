<?php
  // create connection
  $conn = new mysqli("localhost", "root", "", "ct428");

  // check connection
  if($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
  }
?>