<!DOCTYPE html>
<html>
<title>Lap trinh Web(CT428)</title>
<meta http-equiv="Conten-Type" content="text/html" ; charset="UTF-8" />

<body>
  <!--bai 2-->
  <div class="profiles">
    <?php
    session_start();
    if ($_SESSION["tendangnhap"]) {
      $tendangnhap = $_SESSION["tendangnhap"];

      include '../db/connectMySql.php';
      $sql = "select * from thanhvien where tendangnhap = '$tendangnhap'";
      $result = $conn->query($sql);

      if ($result->num_rows > 0) {
        $row = $result->fetch_assoc();
      } else {
        echo "The user $tendangnhap is not exits";
      }
    } else {
      header("Location: dangnhap.html");
    }
    ?>

    <!-- Show profiles -->
    <h2>Thônng tin cá nhân</h2>
    <table>
      <tr>
        <th>
          Id
        </th>
        <th>
          UserName
        </th>
        <th>
          GioiTinh
        </th>
        <th>
          NgheNghiep
        </th>
        <th>
          SoThich
        </th>
        <th>
          HinhAnh
        </th>
      </tr>
      <tr>
        <td>
          <?php echo $row['id'] ?>
        </td>
        <td>
          <?php echo $row['tendangnhap'] ?>
        </td>
        <td>
          <?php echo  $row['gioitinh'] ?>
        </td>
        <td>
          <?php echo  $row['nghenghiep'] ?>
        </td>
        <td>
          <?php echo $row['sothich'] ?>
        </td>
        <td>
          <img src=<?php echo $row['hinhanh'] ?> alt="Smiley face" width="62" height="62">

        </td>
      </tr>
    </table>
  </div>
  <div class="sanpham">
    <a href="./danhSachSanPham.php">Danh Sach SanPham</a>
    <a href="./themSanPham.php">Them SanPham</a>
  </div>
</body>

</html>