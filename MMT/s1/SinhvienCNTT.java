package bai3;

import bai3.Sinhvien;

public class SinhvienCNTT extends Sinhvien {
    SinhvienCNTT(String hoTen, String gioiTinh) {
        super(hoTen, gioiTinh);
    }

    public void diemDanh() {
        System.out.println("Toi la sinh vien CNNT");
    }

    public static void main(String args[]) {
        SinhvienCNTT svcnnt = new SinhvienCNTT("Le Quang Sang", "Nam");
        svcnnt.diemDanh();
    }
}