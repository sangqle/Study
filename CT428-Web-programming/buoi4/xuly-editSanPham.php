<?php
include '../db/connectMySql.php';
session_start();
$tensp = $_POST['tensp'];
$giasp = $_POST['giasp'];
$chitietsp = $_POST['chitietsp'];
$idtv = $_SESSION['idtv'];
$duongdan = "./sanphams/" . $_FILES['avatar']['name'];
$idsp = $_GET['idsp'];

$sql = "update sanpham
        set tensp = '$tensp', chitietsp = '$chitietsp', giasp = '$giasp', hinhanhsp = '$duongdan'
        where idsp = '$idsp'";
$result = $conn->query($sql);
move_uploaded_file($_FILES['avatar']['tmp_name'], $duongdan);
if ($result) {
    header("Location: danhSachSanPham.php");
} else {
    echo $sql;
}
$conn->close();
