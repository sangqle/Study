import java.io.*;
import java.net.*;
import java.util.*;

public class STCPEchoServer {
    public final static int defaultPort = 8080;

    public static void main(String args[]) {
        try {
            ServerSocket ss = new ServerSocket(8080);
            System.out.println("server socket is running");

            while (true) {
                Socket s = ss.accept();
                PrintWriter pw = new PrintWriter(s.getOutputStream());
                BufferedReader brServerSocket = new BufferedReader(new InputStreamReader(s.getInputStream()));
                String dataInput;

                while (true) {
                    dataInput = brServerSocket.readLine();
                    pw.println(dataInput);
                    pw.flush();

                    // Check Ctrl + C and typing "quit" to quit out program
                    if (dataInput == null || dataInput.equals("quit"))
                        break;
                }
                s.close();

            }
        } catch (Exception e) {
            System.out.print(e.toString());
        }
    }
}
