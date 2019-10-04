import java.net.*;
import java.io.*;

public class UDPEchoClient {
	public static void main(String[] args) {
		try {
			if(args.length < 2) {
				System.out.print("Systax: java UDPClient HostName PORT"); return;			
			}
			int serverPort = Integer.valueOf(args[1]).intValue();
			// Tao DatagramSocket
			DatagramSocket ds = new DatagramSocket();
			// Dia chi server
			InetAddress server = InetAddress.getByName(args[0]);
			while(true){
				BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
				String theString = br.readLine();
				// Doi chuoi ra mang bytes
				byte[] data = theString.getBytes();
				// Tao goi tin
				DatagramPacket dp = new DatagramPacket(data, data.length, server, serverPort);
				ds.send(dp); // gui goi tin sang server
				// Tao vung dem de nhan goi tin
				byte[] buffer = new byte[60000];
				DatagramPacket incoming = new DatagramPacket(buffer, buffer.length);
				ds.receive(incoming); // cho nhan goi tinh tra loi tu server
				// Hien thi goi tin ra mang hinh
				System.out.println(new String(incoming.getData(), 0, incoming.getLength()));
			}
			
		} catch(IOException e) {
			System.err.println(e);
		}
	}
}
