<?php
	include "connect.php";
	$tensp = $_POST['tensp'];
	$giasp = $_POST['giasp'];
	$idtv = $_POST['idtv'];
	$duongdan = "./hinhanh/" . $_FILES['hinhanhsp']['name'];
	$sql = "insert into sanpham (tensp, giasp, hinhanhsp,idtv)
		 values ('$tensp', '$giasp', '$duongdan', '$idtv')";
	move_uploaded_file($_FILES['hinhanhsp']['tmp_name'], $duongdan);
	$result = $con->query($sql);
	if($result) {
		echo "Thanh Cong";
	}
?>