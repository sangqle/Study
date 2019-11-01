import java.rmi.*;
import java.net.MalformedURLException;

public class PT1_Server {
	public static void main(String[] args) {
		if(System.getSecurityManager() == null) // cai dat co che bao mat
			System.setSecurityManager(new RMISecurityManager());
			try {
				// tao doi tuong cho phep goi ham tu xa
				PT1 obj = new PT1();
				System.out.println("Tao object cho phep goi tu xa");
				// Dang ky doi tuong
				Naming.rebind("PT1Object", obj);
				System.out.println("Dang ky thanh cong doi tuong");
			} catch(RemoteException e) {
				System.out.println("Loi trong qua trinh tao doi tuong");
			} catch(MalformedURLException e) {
				System.out.println("Loi khi dang ky doi tuong");
			}
	}
}