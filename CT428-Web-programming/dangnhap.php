<?php

	$con = new mysqli("localhost", "root", "", "ct428");
	
	$tendangnhap = $_POST['tendangnhap'];
	$matkhau = md5($_POST['matkhau']);
	
	$sql = "select * from nhanvien where tendangnhap = '$tendangnhap'&& matkhau = '$matkhau'";
	
	$result = $con->query($sql);
      $count = mysqli_num_rows($result);
      // If result matched $myusername and $mypassword, table row must be 1 row
      if($count == 1) {
		 session_start();
         $_SESSION["username"]= "hoih32oi4hoi234hoi23";
         header("location: thongtin-canhan.php");

      }else {
         $error = "Your Login Name or Password is invalid";
		  echo "That bai";
		  echo $sql;
      }
	
	$con->close();
?>
