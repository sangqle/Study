import java.util.Scanner;
class MyDate {
	private int ngay;
	private int thang;
	private int nam;
	// Ham xay dung
	public MyDate() {	// Ham xay dung mac nhien
		ngay = 1; thang = 1; nam = 2000;
	}
	public MyDate(int d, int m, int y) {	// Ham XD 3 tham so
		ngay = d; thang = m; nam = y;
	}
	public MyDate(MyDate d) {		// Ham xay dung sao chep
		ngay = d.ngay; thang = d.thang; nam = d.nam;
	}
	// Ham sao chep sau
	public void makeCopy(MyDate d) {
		ngay = d.ngay; thang = d.thang; nam = d.nam;
	}
	
	// Phuong thuc
	public void nhap() {
		while(true) {
			Scanner kb = new Scanner(System.in);
			System.out.print("Nhap ngay: ");
			ngay = kb.nextInt();
			System.out.print("Nhap thabg: ");
			thang = kb.nextInt();
			System.out.print("Nhap nam: ");
			nam = kb.nextInt();
			if(hopLe()) break;
			System.out.println("Khong hop le - Nhap lai !!!");
		}
	}
	public void hienThi() {
		System.out.print(ngay + "/" + thang + "/" + nam);
	}
	// public boolean hopLe() {
	// 	if(ngay<=0 || thang <=0 || thang>12)
	// 		return false;
	// 	if(thang==2 && nam%4==0 )
	// 		return (ngay<=29);
	// 	int ngaymax[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	// 	return ( ngay <= ngaymax[ thang ]);
	// }



	public boolean hopLe()
	{
		if(ngay < 1 || thang < 1 || thang > 12)
			return false;
		if(thang == 2 && nam %4 == 0)
			return (ngay <= 29);
		int ngaymax[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		return (ngay <= ngaymax[thang]);

	}

	// public MyDate ngayMai() {
	// 	if(ngay==28 && thang==2 && nam%4==0 )
	// 		return new MyDate(29,2,nam);
	// 	MyDate kq = new MyDate(ngay+1,thang,nam);
	// 	int ngaymax[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	// 	if(kq.ngay>ngaymax[kq.thang]) {
	// 		kq.ngay=1;
	// 		kq.thang++;
	// 	}
	// 	if(kq.thang>12) {
	// 		kq.thang=1;
	// 		kq.nam++;
	// 	}
	// 	return kq;
	// }
	public MyDate congNgay(int n) {
		MyDate kq = new MyDate(ngay,thang,nam);
		for(int i=0 ;i<n; i++)
			kq = kq.ngayMai();
		return kq;
	}
	public MyDate ngayMai()
	{
		
		if(ngay==28 && thang ==2 && nam%4==0)
			return new MyDate(29, 2, nam);
		MyDate kq = new MyDate(ngay+1, thang, nam);
		int ngaymax[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if(kq.ngay>ngaymax[kq.thang])
			{
				kq.ngay = 1;
				kq.thang++;
			}
		if(kq.thang>12)
			{
				kq.thang = 1;
				kq.nam++;
			}

        return kq;
	}
	public static void main(String agrs[])
	{
		System.out.print("Nhap voa ngay thang: ");
                MyDate date = new MyDate();
		date.nhap();
		
		    if(date.hopLe()){
					System.out.println("hop le");
					date.hienThi();
				}
			
			date.hienThi();

	}


}