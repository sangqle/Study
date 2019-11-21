import java.io.*;
import java.net.*;
import java.util.*;

public class TCPEchoClient {
    public static void main(String args[]) {
        try {
            if (args.length < 2) {
                System.out.println("Usage: <server name> <port>");
                return;
            }
            // Create a socket to <server name> with <port>
            Socket s = new Socket(args[0], Integer.parseInt(args[1]));

            PrintWriter pw = new PrintWriter(s.getOutputStream());
            BufferedReader brServerSocket = new BufferedReader(new InputStreamReader(s.getInputStream()));
            String dataInput, dataResponse;
            while (true) {
                BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
                dataInput = br.readLine();
                pw.println(dataInput);
                pw.flush();
                dataResponse = brServerSocket.readLine();
                if (dataResponse.equals("quit"))
                    break;
                System.out.println(dataResponse);
            }
            s.close();
        } catch (Exception e) {
            System.out.print(e.toString());
        }
    }
}
