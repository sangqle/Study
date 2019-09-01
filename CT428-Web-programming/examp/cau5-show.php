<?php
    $idtv = $_GET["idtv"];
	include "connect.php";
	$sql = "select * from sanpham where idtv = $idtv";
	$result = $con->query($sql);
	if ($result->num_rows > 0) {
		echo "<table border=1>";
		echo "<tr>";
		echo "<th>STT</th>";
		echo "<th>Tensp</th>";
		echo "<th>Giasp</th>";
		echo "</tr>";
		echo "</table";
		while ($row = $result->fetch_assoc()) {
			echo "<tr>";
			echo "<td>" . $row['idsp'] . "</td>";
			echo "<td>" . $row['tensp'] . "</td>";
			echo "<td>" . $row['giasp'] . "</td>";
			echo "</tr>";
		}
    } else {
        echo "Not found";
    }
