package bai3;

public class Sinhvien {
    String hoTen;
    String gioiTinh;

    Sinhvien(String hoTen, String gioiTinh) {
        this.hoTen = hoTen;
        this.gioiTinh = gioiTinh;
    }

    public void diemDanh() {
        System.out.println("Ho ten: " + this.hoTen + ", Gio tinh: " + this.gioiTinh);
    }
}