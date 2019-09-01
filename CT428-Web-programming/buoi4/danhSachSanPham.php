<html>

<body>
  <?php
  session_start();
  if ($_SESSION["tendangnhap"] && $_SESSION['idtv']) {
    $idtv = $_SESSION["idtv"];

    include '../db/connectMySql.php';
    $sql = "select * from sanpham where idtv = '$idtv'";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
      echo "<table>";
      echo "<tr>";
      echo "<th>idsp</th>";
      echo "<th>Tên sản phẩm</th>";
      echo "<th>Giá sản phẩm</th>";
      // echo "<th>Chi tiết sản phẩm</th>";
      // echo "<th>Hình ảnh</th>";
      echo "</tr>";

      while ($row = $result->fetch_assoc()) {
        $idsp = $row['idsp'];
        echo "<tr>";
        echo "<td>" . $row['idsp'] . "</td>";
        echo "<td>" . $row['tensp'] . "</td>";
        echo "<td>" . $row['giasp'] . "</td>";
        echo "<td><a href='./chiTietSanPham.php?idsp=$idsp'>Details</a></td>";
        echo "<td><a href='./editSanPham.php?idsp=$idsp'>Edit</a></td>";
        echo "<td><a href='./deleteSanPham.php?idsp=$idsp'>Delete</a></td>";
        echo "</tr>";
      }
      echo "</table>";
    }
  } else {
    header("Location: dangnhap.html");
  }
  ?>
  <a href="./themSanPham.php">Thêm sản phẩm mới</a>

</body>

</html>