<html>

<body>
    <?php
    session_start();
    if ($_SESSION["tendangnhap"] && $_SESSION['idtv']) {
        $idtv = $_SESSION["idtv"];
        $idsp = $_GET['idsp'];

        include '../db/connectMySql.php';
        $sql = "select * from sanpham where idtv = '$idtv' && idsp='$idsp'";
        $result = $conn->query($sql);
        $row = $result->fetch_assoc();
        $tensp = $row['tensp'];
        $giasp = $row['giasp'];
        $chitietsp = $row['chitietsp'];

    } else {
        header("Location: dangnhap.html");
    }
    ?>
    <form method="post" action="xuly-editSanPham.php?idsp=<?php echo $idsp ?>" enctype="multipart/form-data">
        <p>Tên sản phẩm</p>
        <input type="text" name='tensp' value='<?php echo $tensp?>' placeholder="Tên SanPham">
        <p>Giá sản phẩm: </p>
        <input type="text" name='giasp' value='<?php echo $giasp?>' placeholder="Giá SanPham">
        <p>Chi tiết sản phẩm</p>
        <textarea name='chitietsp' rows="4" cols="50"><?php echo $chitietsp?></textarea>
        <br>
        <input type="file" name="avatar">
        <br>
        <br>
        <button>Submit</button>
        <button>Cancel</button>
    </form>
</body>

</html>