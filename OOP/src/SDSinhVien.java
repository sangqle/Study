
import java.io.*;
import java.util.logging.Level;
import java.util.logging.Logger;

public class SDSinhVien {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        SinhVien a2 = new SinhVien();
       a2.tuoi = 19;
//		try{
//			SinhVien a = new SinhVien();
//			a.nhapTT();
//			//a.nhapDiem();
//			//a.hienThi();
//			//System.out.println("Diem TB: " + a.diemTB());
//                        // Tiến hành ghi đối tượng
//                        FileOutputStream fos = new FileOutputStream("test.txt");
//                        // tạo luồng xuất đối tượng
//                        ObjectOutputStream obf = new ObjectOutputStream(fos);
//                        // tiến hành ghi object vào file
//                        obf.writeObject(a);
//                        obf.flush();
//                        obf.close();
//                }catch(FileNotFoundException e)
//                {
//                    System.out.println("Loi khong tim thay file");
//                }
//               catch(IOException e)
//               {
//                   System.out.println("loi nhap xuat");
//               }
//
//            // Tiến hành đọc file đối tượng
//            System.out.println("----------------------------------");
//            System.out.println("Thong tin sinh vien\n");
//            ObjectInputStream ios = new ObjectInputStream(new FileInputStream("test.txt"));
//            SinhVien b = null;
//            try {
//                b = (SinhVien)ios.readObject();
//                ios.close();
//            } catch (ClassNotFoundException ex) {
//                Logger.getLogger(SDSinhVien.class.getName()).log(Level.SEVERE, null, ex);
//            }
//            b.hienThi();

        int n = 3;
        SinhVien a[] = new SinhVien[n];
        for (int i = 0; i < n; i++) {
            a[i] = new SinhVien();
            a[i].nhapTT();

        }

//            System.out.println("Diem tb: "+a.DiemTb());
        System.out.println("---------------------------------");
        //Tiến hành ghi object vô file
        ObjectOutputStream bos = new ObjectOutputStream(new FileOutputStream("test2.ser"));
        for (int i = 0; i < n; i++) {
            bos.writeObject(a[i]);
            bos.flush();
        }
        bos.close();
        // Đọc file lấy thông tin sinh viên
        ObjectInputStream ios = new ObjectInputStream(new FileInputStream("test2.ser"));
        SinhVien c[] = new SinhVien[n];
        for (int i = 0; i < n; i++) {
            c[i] = null;
            try {
                c[i] = (SinhVien) ios.readObject();
                //d = (SinhVien)ios.readObject();
                System.out.println("-----------------------");
                System.out.println("Thong tin sinh vien " + (i + 1));
                c[i].hienThi();

            } catch (ClassNotFoundException ex) {
                Logger.getLogger(SDSinhVien.class.getName()).log(Level.SEVERE, null, ex);
            }

        }
        ios.close();

    }
}
