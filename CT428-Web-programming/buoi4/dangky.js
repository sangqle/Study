console.log("hello world");

var check = true;
function validateForm() {
  var tendangnhap = document.forms["dangky"]["tendangnhap"].value;
  var matkhau = document.forms["dangky"]["matkhau"].value;
  var matkhau2 = document.forms["dangky"]["matkhau2"].value;
  var gioitinh = document.forms["dangky"]["gioitinh"].value;
  var nghenghiep = document.forms["dangky"]["nghenghiep"].value;

  var patternPass = /^(?=.*[A-Za-z])(?=.*[0-9])[A-Za-z0-9]{4,13}$/;
  var patternTendangnhap = /^[A-Za-z][A-Za-z0-9]{6,15}$/;


  if(!patternTendangnhap.test(tendangnhap)) {
    check = false;
    document.getElementById("checkTendangnhap").innerHTML =
      "Tendangnhap is not valid";
  }
  if (!patternPass.test(matkhau)) {
    check = false;
    document.getElementById("checkMatkhau").innerHTML =
      "6-15 character, uppercase, lowercase & Number";
  }
  if (gioitinh.length === 0) {
    check = false;
    document.getElementById("checkGioitinh").innerHTML = "not null";
  }
  if (matkhau !== matkhau2) {
    check = false;
    document.getElementById("checkMatkhau2").innerHTML =
      "Password does not match.";
  }
  console.log(tendangnhap)
  console.log(matkhau);
  console.log(matkhau2);
  return check;
}
