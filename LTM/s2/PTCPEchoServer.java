import java.io.*;
import java.net.*;
import java.util.*;

public class PTCPEchoServer {
    public final static int defaultPort = 2019;

    public static void main(String args[]) {
        try {
            ServerSocket ss = new ServerSocket(defaultPort);
            System.out.println("server socket is running");
            while (true) {
		try {
		    Socket s = ss.accept();
		    // Tao xu ly
		    RequestProcessing rq = new RequestProcessing(s);
		    rq.start();
		} catch(IOException e) {
			System.out.println("connection Error: " + e);
		}
		
		}
        } catch (Exception e) {
            System.out.println("Creat Socket Error: " + e);
        }
    }
}
