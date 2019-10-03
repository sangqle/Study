import java.io.*;
import java.net.*;
import java.util.*;

public class chatBotServer {
    public static void main(String[] args) {
        // Handle error
        if(args.length < 1) {
            System.out.println("Port number is required but not provided");
            return;
        }
        // Build hash table
        Hashtable<String, String> question = new Hashtable<String, String>();
        question.put("hi", "Hello");
        question.put("bye", "Goodbye see you later.");

        // New server socket
        try {
            int port = Integer.parseInt(args[0]);
            ServerSocket ss = new ServerSocket(port);
            System.out.println("Server is running on " + port);
            int numConnection = 1;

            while(true) {

                Socket s = ss.accept();
                System.out.println("Connection " + numConnection + ": " + s);
                numConnection++;

                BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
                PrintWriter pw = new PrintWriter(s.getOutputStream());
                while(true) {
                    // Get quesion form client.
                    String a, q;
                    q = br.readLine();
                    q = q.toLowerCase();
                    
                    boolean find = question.containsKey(q);
                    if(find == true) a = question.get(q);
                    else a = "Chatbot: I am listing you.";
                    // Wrint into client
                    pw.println("Chatbot: " + a);
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