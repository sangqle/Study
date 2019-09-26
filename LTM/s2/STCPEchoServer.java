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
                OutputStream os = s.getOutputStream();
                InputStream is = s.getInputStream();
                int ch = 0;
                while (true) {
                    ch = is.read();
                    if (ch == -1)
                        break;
                    System.out.print((char) ch);
                    os.write(ch);
                }
                s.close();

            }
        } catch (Exception e) {
            System.out.print(e.toString());
        }
    }
}
