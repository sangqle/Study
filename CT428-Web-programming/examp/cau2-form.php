<!DOCTYPE html>
<html>
<head>
	<title>cau 2</title>
	<meta charset="utf-8">
</head>
<body>
	<form name="themsp" action="cau2-xuly.php" method="POST" enctype="multipart/form-data" onsubmit="return validation()">
		<p>Tên sản phẩm</p>
		<input type="text" name="tensp">
		<p>Giá sản phẩm</p>
		<input type="text" name="giasp">		
		<p>Hình ảnh sản phẩm</p>
		<input type="file" name="hinhanhsp">
		<p>Chọn thành viên</p>

		<select name="idtv">
		<?php 
			include "connect.php";
			$sql = "select id from thanhvien";
			$result = $con->query($sql);	
			if($result->num_rows > 0) {
				while($row = $result->fetch_assoc()) {
					echo "<option>".$row['id']."</option>";
				}
			}
		?>
		</select>
		<button>Them</button>
		<input type="reset" name="">
	</form>
</body>
<script type="text/javascript">
	function validation() {
		var tensp = document.forms["themsp"]["tensp"].value;
		var hinhanhsp = document.forms["themsp"]["hinhanhsp"].files.length;
		if(tensp == "" || hinhanhsp == 0) {
			alert("you have to fill full for process");
			return false
		}
	}
</script>
</html>

