<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <meta http-equiv="X-UA-Compatible" content="ie=edge">
  <title>Document</title>
  <script type="text/javascript">
    function chonThanhVien(value) {
      var xmlhttp;
      xmlhttp = new XMLHttpRequest();

      xmlhttp.onreadystatechange = function() {
        if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
          document.getElementById("tv").innerHTML = xmlhttp.responseText;
        }
      };
      xmlhttp.open("GET", "cau5-show.php?idtv=" + value, true);
      xmlhttp.send();
    }
  </script>
</head>

<body>
  <h1>Danh Sach Thanh Vien </h1>
  <select onchange="chonThanhVien(value)">
    <?php
    include "connect.php";
    $sql = "select * from thanhvien";
    $result = $con->query($sql);
    if ($result->num_rows > 0) {
      while ($row = $result->fetch_assoc()) {
        echo "<option value=" . $row['id'] . ">" . $row['tendangnhap'] . "</option>";
      }
    }
    ?>
  </select>
  <div id="tv"></div>
</body>

</html>