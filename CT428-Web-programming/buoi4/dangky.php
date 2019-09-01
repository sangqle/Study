<html>

<body>
  <?php

  $tendangnhap = $_POST['tendangnhap'];
  $matkhau = md5($_POST['matkhau']);
  $duongdan = "./images/" . $_FILES['avatar']['name'];
  $gioitinh = $_POST['gioitinh'];
  $nghenghiep = $_POST['nghenghiep'];
  $sothich = implode(',', $_POST['sothich']);

  function dangKyThanhVien($sql)
  {
    include '../db/connectMySql.php';
    $result =  $conn->query($sql);
    if (!$result) {
      throw new Exception(" Error insert to database ");
    }
    return true;
  }

  try {
    $sql =  " insert into thanhvien (tendangnhap, matkhau, hinhanh, gioitinh, nghenghiep, sothich)
	values ('$tendangnhap', '$matkhau', '$duongdan', '$gioitinh', '$nghenghiep', '$sothich') ";
    dangKyThanhVien($sql);
    move_uploaded_file($_FILES['avatar']['tmp_name'], $duongdan);
    header("Location: dangnhap.html ");
  } catch (Exception  $e) {
    echo  $sql;
    echo 'Message: ' .  $e->getMessage();
  }

  $conn->close();
  ?>

</body>

</html>