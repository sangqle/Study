import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class PT1 extends UnicastRemoteObject implements PT1_Itf {
	public PT1() throws RemoteException {
		super();
	}
	// cai dat ham goi tu xa
	public String GiaiPT1(float a, float b) {
		if(b == 0 && (a == 0 || a != 0)) return "x = 0";
		else if(a == 0 && b != 0) return "Pt vo nghiem";
		else return "x = " + Float.toString(-b/a);
	}
	public String KyVong(float[] a) {
		float sum = 0;
		float Ea = 0;
		float Aa = 0;
		for(int i = 0; i < a.length; i++) {
			sum += a[i];
		}
		Ea = sum/a.length;
		for(int i = 0; i < a.length; i++) {
			sum += Math.pow((a[1] - Ea), 2);
		}
		Aa = sum;
		return "E = " + Float.toString(Ea) + ", " + "A = " + Float.toString(Aa);
	}
	public float[][] NhanMatran(float[][] a, float[][] b) {
		float[][] c = new float[a.length][b[0].length];
		for(int i = 0; i < a.length; i++) {
			for(int j = 0; j < a[i].length; j++) {
				for(int t = 0; t < b[j].length; t++) {
					c[i][t] += a[i][j] * b[j][t]; 
				}
			}
		}
		return c;
	}
}