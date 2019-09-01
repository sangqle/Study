<html>

<body>
  <?php
  session_start();
  if (!$_SESSION['tendangnhap']) {
    header('Location: dangnhap.html');
  }
  ?>

  <h2>Thêm sản phẩm</h2>
  <form method="post" action="xuly-themSanPham.php" enctype="multipart/form-data">
    <p>Tên sản phẩm</p>
    <input type="text" name='tensp' placeholder="Tên SanPham">
    <p>Giá sản phẩm: </p>
    <input type="text" name='giasp' placeholder="Giá SanPham">
    <p>Chi tiết sản phẩm</p>
    <textarea name='chitietsp' rows="4" cols="50"></textarea>
    <br>
    <input type="file" name="avatar">
    <br>
    <br>
    <button>Submit</button>
    <button>Cancel</button>
  </form>

</body>

</html>