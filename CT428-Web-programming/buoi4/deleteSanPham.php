<?php
include '../db/connectMySql.php';
session_start();
$idsp = $_GET['idsp'];

$sql = "delete from sanpham
        where idsp = '$idsp'";
$result = $conn->query($sql);

if ($result) {
    header("Location: danhSachSanPham.php");
} else {
    echo $sql;
}
$conn->close();
