import java.io.*;
import java.net.*;
import java.util.*;

public class TCPEchoClient {
    public static void main(String args[]) {
        try {
            Socket s = new Socket(args[0], Integer.parseInt(args[1]));
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

