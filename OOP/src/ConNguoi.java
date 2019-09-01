
import java.io.Serializable;
import java.util.Scanner;

public class ConNguoi implements Serializable{
    private String quocTich;
    protected String gioiTinh;
    int tuoi;

    public ConNguoi()
    {
        quocTich = new String("VietNam");
        gioiTinh = new String("Nam");
    }
    public ConNguoi(ConNguoi cn)
    {
        this.quocTich = new String(cn.quocTich);
        this.gioiTinh = new String(cn.gioiTinh);
    }
    public void makeCoppy(ConNguoi cn)
    {
        quocTich  = new String(cn.quocTich);
        gioiTinh = new String(cn.gioiTinh);
    }
    public void nhapTT()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Nhap vao QuocTich: ");
        quocTich = sc.nextLine();
        System.out.println("Nhap vao GioiTinh: ");
        gioiTinh = sc.nextLine();

    }
    public void hienThi()
    {
        System.out.println("Quoc Tich: "+quocTich + "  GioiTinh: "+gioiTinh);
    }

    
}
