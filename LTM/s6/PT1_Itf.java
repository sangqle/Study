import java.rmi.Remote;
import java.rmi.RemoteException;
public interface PT1_Itf extends Remote {
	public String GiaiPT1(float a, float b) throws RemoteException;
	public String KyVong(float[] a) throws RemoteException;
	public float[][] NhanMatran(float[][] a, float[][] b) throws RemoteException;
}