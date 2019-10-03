import java.io.*;
import java.net.*;
import java.util.*;
import java.util.Scanner;  // Import the Scanner class

public class chatServer {
    public static void main(String[] args) {
        // Handle error
        if(args.length < 1) {
            System.out.println("Port number is required but not provided");
            return;
        }
        // New server socket
        try {
            int port = Integer.parseInt(args[0]);
            ServerSocket ss = new ServerSocket(port);
            System.out.println("Server is running on " + port);

            while(true) {

                Socket s = ss.accept();
                Scanner sc = new Scanner(System.in);  // Create a Scanner object
                BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
                PrintWriter pw = new PrintWriter(s.getOutputStream());
                while(true) {
                    // Get quesion form client.
                    String q;
                    q = br.readLine();
                    System.out.println("Client: " + q);

                    String a = "";
                    System.out.print("Server: ");
                    a = sc.nextLine();

                    pw.println("Server: " + a);
                    pw.flush();
                    
                    if(q.equals("bye")) break;
                }
                s.close();
            }
        } catch(Exception e) {
            System.out.println(e);
        }
    }
}