package Game;

import java.util.Scanner;
import java.io.*;
public class Cuop implements Serializable {
	private String Maso;
	private ToaDo vitri;
	private int rare; // mức độ nguyen hiểm
	private int noinang; // năng lương còn lại
	private String sotruong;
	//ham xd mac nhien
	public Cuop() {
		Maso=new String();
		vitri=new ToaDo();
		rare=0;
		noinang=0;
		sotruong=new String();
	}
	//xd voi tat ca cac doi so
	public Cuop(String Maso,ToaDo vitri,int rare,int noinang,String sotruong) {
		this.Maso=Maso;
		this.vitri=vitri;
		this.rare=rare;
		this.noinang=noinang;
		this.sotruong=sotruong;
	}
	
	public Cuop(Cuop cuop) {
		this.Maso= new String(cuop.Maso);
		this.vitri= new ToaDo(cuop.vitri);
		this.rare= cuop.rare;
		this.noinang= cuop.noinang;
		this.sotruong=new String(sotruong);
		// TODO Auto-generated constructor stub 
	}
	public void nhap() {
		Scanner b=new Scanner(System.in);
		System.out.print("\nNhap ma so: ");
		Maso=b.nextLine();
		System.out.print("\nNhap vi tri: ");
		vitri.nhapTD();
		System.out.print("\nNhap nguy hiem: ");
		rare=b.nextInt();
		System.out.print("\nNhap noi nang:");
		noinang=b.nextInt();
		b.nextLine();
		System.out.print("\nNhap so truong: ");
		sotruong=b.nextLine();
	}
	public void hienthi() {
		System.out.print("\nma so:"+Maso);
		vitri.xuat(); // chổ này nè. coi thử hàm xuất chổ vị trí có full tọa độ chưa
		System.out.print("\nnguy hiem: "+rare);
		System.out.print("\nnoi nang: "+noinang);
		System.out.print("\nso truong: "+sotruong);
	}
	public void doivitri(int a,int b) {
		vitri.setHd(a);
                vitri.setTd(b);
	}
	public void giam() {
		noinang  = noinang--;
	}
       
	public int day() {
		return this.noinang=100;
	}


	
}
