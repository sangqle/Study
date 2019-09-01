<?php 
	include "connect.php";
	$sql="select * from sanpham order by idsp desc limit 2";
	$result = $con->query($sql);
	
	echo "<table "."border=1".">";
	echo "<tr>";
		echo "<th>STT</th>";
		echo "<th>TenSp</th>";
		echo "<th>GiaSp</th>";
	echo "</tr>";
	if($result->num_rows > 0) {

		while($row = $result->fetch_assoc()) {
			echo "<tr>";
			echo "<th>".$row['idsp']."</th>";
			echo "<th>".$row['tensp']."</th>";
			echo "<th>".$row['giasp']."</th>";
			echo "</tr>";
		}
	}
	echo "</table>";
	
?>
<!DOCTYPE html>
<html>
<head>
	<title>Cau 1</title>
	<meta charset="utf-8">

</head>

<body>
	<p id="time"></p>
	show
</body>
<script type="text/javascript">
	var timeDisplay = document.getElementById("time");
		function refreshTime() {
			timeDisplay.innerHTML = new Date().toLocaleString();
		}
	setInterval(refreshTime, 1000);
</script>
</html>
