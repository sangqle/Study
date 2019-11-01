import java.rmi.*;
import java.net.MalformedURLException;
import java.util.Scanner;

public class PT1_Client {
	public static void main(String[] args) {
		try {
			// Do tim doi tuong
			PT1_Itf ref = (PT1_Itf)Naming.lookup("rmi://" + args[0] + "/PT1Object");
			// Goi ham tren doi tuong
			float a, b;
			
			int nA = 0;
			Scanner sc = new Scanner(System.in);
			while(true) {
				int option;
				System.out.print("Option 1 for giaPT1, 2 for KyVong and 0 for the end: ");
				option = sc.nextInt();
				if(option == 0) return;
				else if(option == 1) {
					System.out.print("Nhap vao a: ");
					a = sc.nextFloat();
					System.out.print("Nhap vao b: ");
					b = sc.nextFloat();
					String result = ref.GiaiPT1(a, b);
					System.out.println("ket qua: " + result);
				} else if(option == 2) {
					System.out.print("Nhap vao so pt day so a: ");
					nA = sc.nextInt();
					float[] dayA = new float[nA];
					for(int i = 0; i < nA; i++) {
						dayA[i] = sc.nextFloat();
					}
					String result1 = ref.KyVong(dayA);
					System.out.println("ket qua: " + result1);
				}
			}	
			
		} catch(NotBoundException e) {
			System.out.println("Khong tim thay doi tuong");
		} catch(MalformedURLException e) {
			System.out.println("Sai trong dinh dang URL");
		} catch(RemoteException e) {
			System.out.println("Loi trong khi goi ham tu xassss");
		}
	}
}