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

    if ($result->num_rows > 0) {
      echo "<table>";
      echo "<tr>";
      echo "<th>id</th>";
      echo "<th>Tên sản phẩm</th>";
      echo "<th>Giá sản phẩm</th>";
      // echo "<th>Chi tiết sản phẩm</th>";
      // echo "<th>Hình ảnh</th>";
      echo "</tr>";

      while ($row = $result->fetch_assoc()) {
        echo "<tr>";
        echo "<td>" . $row['idsp'] . "</td>";
        echo "<td>" . $row['tensp'] . "</td>";
        echo "<td>" . $row['giasp'] . "</td>";
        echo "<td>" . $row['chitietsp'] . "</td>";
        echo "<td><img src= " .$row['hinhanhsp'] ." alt='Smiley face' width= '62' height= '62'></td>";
          
        echo "</tr>";
      }
      echo "</table>";
    }
  } else {
    header("Location: dangnhap.html");
  }
  ?>
</body>

</html>