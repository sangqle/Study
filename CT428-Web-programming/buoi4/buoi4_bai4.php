<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Document</title>
</head>




<body>

    <div id="wrap">
        <div id="title">
            <h1>Bài 2 - Buổi 4</h1>
        </div>
        <!--end div title-->
        <div id="menu">
            <!-- chèn menu của sinh viên vào-->
        </div>
        <!--end div menu-->
        <div id="content">
            <!--Nội dung trang web-->
            <h1>Slide show</h1>

            <form name="form">
                <img id="laptopImg" src="" height="300" width="300" />
                <br />
                <input type="button" name="previous" value="Previous" onclick="changeSlide(-1)">
                <input type="button" name="next" value="Next" onclick="changeSlide(1)">
                <br />
                <select id="laptopSel" name="laptopSel" onchange="chooseSlide(value)">
                    
                </select>
            </form>
</body>

<script>
    var IMAGE_PATHS = [];
    var dsSanPham = [];
    var i = 0;

    <?php
    session_start();
    if ($_SESSION["tendangnhap"] && $_SESSION['idtv']) {
        $idtv = $_SESSION["idtv"];

        include '../db/connectMySql.php';
        $sql = "select * from sanpham where idtv = '$idtv'";
        $result = $conn->query($sql);
        if ($result->num_rows > 0) {
            while ($row = $result->fetch_assoc()) {
                ?>
                IMAGE_PATHS[i] = '<?php echo $row['hinhanhsp'] ?>'
                dsSanPham[i] = '<?php echo $row['tensp']?>'
                i++;
            <?php

        }
    }
} else {
    header("Location: dangnhap.html");
}
?>

    console.log(IMAGE_PATHS)

    var img = document.getElementById("laptopImg");

    img.setAttribute('src', IMAGE_PATHS[0])

    var index = 0;

    var select = document.getElementById("laptopSel");

    for(i in dsSanPham) {
        select.options[select.options.length] = new Option(dsSanPham[i], i)
    }

    console.log(select)
    function changeSlide(pos) {
        index = index + pos;
        if (index === IMAGE_PATHS.length) index = 0;
        if (index === -1) index = IMAGE_PATHS.length - 1;
        var img = document.getElementById("laptopImg");
        img.setAttribute('src', IMAGE_PATHS[index])
        console.log(IMAGE_PATHS[index]);
        chooseSlide(index);
    }

    function chooseSlide(pos) {
        var img = document.getElementById("laptopImg");
        var select = document.forms['form']['laptopSel'];
        document.forms['form']['laptopSel'].value = pos;
        img.setAttribute('src', IMAGE_PATHS[pos])
        console.log(pos);
    }
</script>

</html>