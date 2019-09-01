import java.util.Scanner;
import java.io.Serializable;
class SinhVien extends ConNguoi implements Serializable{
	private String maso;
	private String hoten;
	//private MyDate ngaysinh;
	private	int	soluong;
	private String	hocphan[];
        private String	diem[];

    public String getMaso() {
        return maso;
    }

    public void setMaso(String maso) {
        this.maso = maso;
    }

    public String getHoten() {
        return hoten;
    }

    public void setHoten(String hoten) {
        this.hoten = hoten;
    }

    public int getSoluong() {
        return soluong;
    }

    public void setSoluong(int soluong) {
        this.soluong = soluong;
    }

    public String[] getHocphan() {
        return hocphan;
    }

    public void setHocphan(String[] hocphan) {
        this.hocphan = hocphan;
    }

    public String[] getDiem() {
        return diem;
    }

    public void setDiem(String[] diem) {
        this.diem = diem;
    }
	
	// Ham xay dung
	public SinhVien() {
		super(); // gọi hàm xây dựng của lớp cha
		maso = new String();
		hoten = new String();
		//ngaysinh = new MyDate();
		soluong = 0;
		hocphan = new String[20]; // khởi tạo mảng gồm 20 phần tử kiểu String
		diem = new String[20];
	}
	public SinhVien(SinhVien sv) { // xây dựng soa chếp
        super(sv);
		maso = new String(sv.maso);
		hoten =  new String(sv.hoten);
		//ngaysinh = new MyDate(sv.ngaysinh);
		soluong = sv.soluong;
		hocphan = new String[20];
		diem = new String[20];
		for(int i=0; i<soluong; i++) {
			hocphan[i] = new String(sv.hocphan[i]);
			diem[i] = new String(sv.diem[i]);
		}
	}
	// Ham sao chep sau
	public void makeCopy(SinhVien sv) {
        super.makeCoppy(sv);
		maso = new String(sv.maso);
		hoten = new String(sv.hoten);
		//ngaysinh.makeCopy(sv.ngaysinh);
		soluong = sv.soluong;
		for(int i=0; i<soluong; i++) {
			hocphan[i] = new String(sv.hocphan[i]);
			diem[i] = new String(sv.diem[i]);
		}
	}
	// Cac phuong thuc khac
	public void nhapTT() {
        super.nhapTT();
		Scanner kb = new Scanner(System.in);
//		System.out.print("Nhap ma so sinh vien: ");
//		maso = kb.nextLine();
		System.out.print("Nhap ho ten sinh vien: ");
		hoten = kb.nextLine();
//		System.out.println("Nhap ngay sinh: ");
//		ngaysinh.nhap();
//		System.out.print("Nhap so luong mon dang ky: ");
//		soluong = kb.nextInt();
//		kb.nextLine();
//		System.out.println("Nhap ten cac hoc phan dang ky: ");
//		for(int i=0; i<soluong; i++) {
//			System.out.print("Nhap hoc phan thu " + (i+1)+ ": ");
//			hocphan[i] = kb.nextLine();
//		}
	}
	public void nhapDiem() {
		Scanner kb = new Scanner(System.in);
		System.out.println(hoten + " MSSV " + maso);
		for(int i=0; i<soluong; i++) {
			System.out.print(hocphan[i]+ ": ");
			diem[i] = kb.nextLine();
		}
	}
	public void hienThi() {
        super.hienThi();
		System.out.println("Ho ten SV: " + hoten);
		//System.out.println("MSSV: " + maso);
		//System.out.print("Ngay sinh: ");
		//ngaysinh.hienThi();
		System.out.println();
		//System.out.println("So mon dang ky: " + soluong);
//		System.out.println("Diem hoc phan");
		for(int i=0; i<soluong; i++) 
			System.out.println(hocphan[i] + ": " + diem[i]);
	}
	// public float diemTB() {
	// 	float tong=0;
	// 	for(int i=0; i<soluong; i++)
	// 		switch(diem[i]) {
	// 			case "A":	tong += 4.0; break;
	// 			case "B+":	tong += 3.5; break;
	// 			case "B":	tong += 3.0; break;
	// 			case "C+":	tong += 2.5; break;
	// 			case "C":	tong += 2.0; break;
	// 			case "D+":	tong += 1.5; break;
	// 			case "D":	tong += 1.0; break;
	// 		}
	// 	return (float)tong/soluong;
	// }
	public void themHP(String tenhp) {
		hocphan[soluong] = tenhp;
		soluong++;
	}
	public void xoaHP(int i) {
		if(i<0 || i>=soluong)
			System.out.println("Khong xoa duoc");
		else {
			for(int j=i; j<soluong-1; j++) {
				hocphan[j]=hocphan[j+1];
				diem[j]=diem[j+1];
			}
			soluong--;
		}
	}

	public float DiemTb()
	{
        float tong = 0;
		for(int i = 0; i < soluong; i++)
		{
			switch(diem[i])
			{
				case "A" : tong+= 4; break;
				case "B+": tong+= 3.5; break;
				case "B" : tong+= 3; break;
				case "C+": tong+= 2.5; break;
				case "C": tong+= 2; break;
				case "D+": tong+= 1.5; break;
				case "D": tong+= 1; break;
			}
		}
		return tong/soluong;

	}

}