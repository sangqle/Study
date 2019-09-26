import java.io.*;
import java.net.*;
import java.util.*;

public class TCPEchoClient {
    public static void main(String args[]) {
        try {
<<<<<<< HEAD
            Socket s = new Socket(args[0], 8080);
=======
            Socket s = new Socket(args[0], Integer.parseInt(args[1]));
>>>>>>> bda5d66a4fed8fb3b41f1c4beddf7beb34ccd26c
            InputStream is = s.getInputStream();
            OutputStream os = s.getOutputStream();
            while (true) {
                BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
                String theString = br.readLine();
                byte[] data = theString.getBytes();
                String quit = new String("quit");
                if (Arrays.equals(quit.getBytes(), data)) {
                    System.out.println("Quit");
                    break;
                }
                for (int i = 0; i < data.length; i++) {
                    os.write(data[i]);
                    int ch = is.read();
                    System.out.print((char) ch);
                }
                System.out.println();
            }
            s.close();
        } catch (Exception e) {
            System.out.print(e.toString());
        }
    }
}

