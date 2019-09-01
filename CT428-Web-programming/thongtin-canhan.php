<!DOCTYPE html>
<html>
  <title>Lap trinh Web(CT428)</title>
  <meta http-equiv="Conten-Type" content="text/html"; charset="UTF-8"/>
  <body>
  <!--bai 2-->
	<div class="form-sign-in">
		<h2>Thong tin ca nhan</h2>
		<?php
		session_start();
		echo "Favorite color is " . $_SESSION["username"] . ".<br>";
		?>
		
	</div>

  </body>
</html>