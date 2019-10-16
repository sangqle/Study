import java.net.*;
import java.io.*;

public class UDPEchoServer {
	public static void main(String[] args) {
		try {
			if(args.length < 1) {System.out.println("Enter PORT..."); return;}
			// Tao socket
			int port = Integer.valueOf(args[0]).intValue();
			DatagramSocket ds = new DatagramSocket(port);
			System.out.println("Created UDP Socket...");
			// Buffer
			byte[] buffer = new byte[60000];
			while(true){
				DatagramPacket in = new DatagramPacket(buffer, buffer.length);
				ds.receive(in);
				// Lay du lieu khoi tin nhan
				String str = new String(in.getData(), 0, in.getLength());
				//Tao goi tin goi chua du lieu vua nhan
				DatagramPacket out = new DatagramPacket(str.getBytes(), in.getLength(), in.getAddress(), in.getPort());
				ds.send(out);
			}
		} catch(IOException e) {
			System.err.println(e);
		}
	}
}
