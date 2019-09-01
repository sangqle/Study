<html>

<body>
  <?php
  include '../db/connectMySql.php';
  $tendangnhap = $_POST['tendangnhap'];
  $matkhau = md5($_POST['matkhau']);

  $sql = "select * from thanhvien where tendangnhap = '$tendangnhap' && matkhau = '$matkhau'";

  $result = $conn->query($sql);
  $count = mysqli_num_rows($result);
  
  $row = $result->fetch_assoc();
  echo $row['id'];
  if ($count == 1) {
    session_start();
    $_SESSION["tendangnhap"] = $tendangnhap;
    $_SESSION["idtv"] = $row['id'];
    header("location: thongtin-canhan.php");
  } else {
    echo "Incorrect email or password.";
  }
  $conn->close();
  ?>

</body>

</html>