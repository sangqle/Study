import java.rmi.*;
import java.net.MalformedURLException;
import java.util.Scanner;

public class PT1_Client {
	static void input(float[][] a, int m, int n) {
		Scanner sc = new Scanner(System.in);
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				a[i][j] = sc.nextFloat();
			}
			System.out.println();
		}
	}
	static void output(float[][] c) {
		for(int i = 0; i < c.length; i++) {
			for(int j = 0; j < c[i].length; j++) {
				System.out.print(c[i][j] + " ");
			}
			System.out.println();
		}
	}
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
				System.out.print("Option 1 for giaPT1, 2 for KyVong, 3 for multiply matrix and 0 for the end: ");
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
				} else if(option == 3) {
					int m, n;
					System.out.println("Nhap vao matran A: ");
					System.out.println("Nhap vao so hang (m) cua matran A: ");
					m = sc.nextInt();
					System.out.println("Nhap vao so cot (n) cua matran A: ");
					n = sc.nextInt();
					System.out.println(">>>");
					
					float[][] aMatrix = new float[m][n];
					input(aMatrix, m, n);
					
					System.out.println("Nhap vao matran B: ");
					System.out.println("Nhap vao so hang (m) cua matran B: ");
					m = sc.nextInt();
					System.out.println("Nhap vao so cot (n) cua matran B: ");
					n = sc.nextInt();
					System.out.println(">>>");
					
					float[][] bMatrix = new float[m][n];
					input(bMatrix, m, n);
					float[][] cMatrix = ref.NhanMatran(aMatrix, bMatrix);
					System.out.println("ket qua: ");
					output(cMatrix);
					
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