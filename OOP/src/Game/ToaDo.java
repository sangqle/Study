package Game;

import java.util.Scanner;
import java.io.*;

public class ToaDo implements Serializable{

    private int hd;
    private int td;
    //ham xay dung mac nhien

    public ToaDo() {
        this.hd = 0;
        this.td = 0;
    }

    public ToaDo(int x, int y) {
        this.hd = x;
        this.td = y;
    }

    public ToaDo(ToaDo x) {
        this.hd = x.hd;
        this.td = x.td;
    }

    public void nhapTD() {
        Scanner b = new Scanner(System.in);
        System.out.print("\nnhap hoanh do: ");
        hd = b.nextInt();
        System.out.print("\nnhap tung do:");
        td = b.nextInt();
    }

    public void xuat() {
        System.out.print("\n(" + hd + "," + td + ")");
    }

    public int getHd() {
        return hd;
    }

    public void setHd(int hd) {
        this.hd = hd;
    }

    public int getTd() {
        return td;
    }

    public void setTd(int td) {
        this.td = td;
    }

    public void DoiToaDo(int a, int b) {
        setTd(a);
        setHd(b);
    }

    public void cac(int a, int b) {
        this.hd = a;
        this.td = b;
    }
}
