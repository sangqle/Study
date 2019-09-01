<?php

	$con = new mysqli("localhost", "root", "", "ct428");
	
	
	$tendangnhap = $_POST['tendangnhap'];
	$matkhau = md5($_POST['matkhau']);
	$hinhanh = $_POST['hinhanh'];
	$gioitinh = $_POST['gioitinh'];
	$nghenghiep = $_POST['nghenghiep'];
	$sothich = $_POST['sothich'];
	
	$sql = "insert into nhanvien(tendangnhap, matkhau, hinhanh, gioitinh, nghenghiep, sothich)
	values('$tendangnhap', '$matkhau', '$hinhanh', '$gioitinh', '$nghenghiep', '$sothich')";
	
	$con->query($sql);
	echo $sql;
	$con->close();
	
?>
