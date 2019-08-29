package bai3;

import bai3.Sinhvien;

public class SinhvienMMT extends Sinhvien {
    SinhvienMMT(String hoTen, String gioiTinh) {
        super(hoTen, gioiTinh);
    }

    public void diemDanh() {
        System.out.println("Toi la sinh vien TT-MMT");
    }

    public static void main(String args[]) {
        SinhvienMMT svmmt = new SinhvienMMT("Le Quang Sang", "Nam");
        svmmt.diemDanh();
    }
}