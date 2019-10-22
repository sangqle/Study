import java.io.*;
import java.net.*;

public class SMTPClient {
  public static void main(String[] args) {
    if (args.length < 2) {
      System.out.println("Usage: SMTPClient <server mail> <PORT>");
      return;
    }
    int PORT = Integer.valueOf(args[1]).intValue();

    try {
      Socket s = new Socket(args[0], PORT);
      BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
      BufferedReader key = new BufferedReader((new InputStreamReader(System.in)));
      PrintWriter pw = new PrintWriter(s.getOutputStream());

      String mailFrom = "";
      String mailTo = "";

      // Read greeting from server
      String respone = br.readLine();
      System.out.println(respone);
      if (!respone.startsWith("220")) {
        throw new IOException("220 reply not recieve from serevr");
      }

      // Send HELO and get respone from server
      pw.println("HELO");
      pw.flush();
      respone = br.readLine();
      if (!respone.startsWith("250")) {
        throw new IOException("250 reply not recieve from serevr");
      }

      // Send MAIL FROM command
      System.out.println("Please enter the source e-mail address: ");
      mailFrom = key.readLine();
      pw.println("MAIL FROM: " + mailFrom);
      pw.flush();
      respone = br.readLine();
      if (!respone.startsWith("250")) {
        throw new IOException("250 reply not recieve from serevr");
      }

      // Send RECP TO command
      System.out.println("Please enter the destination e-mail address: ");
      mailTo = key.readLine();
      pw.println("RCPT TO: " + mailTo);
      pw.flush();
      respone = br.readLine();
      if (!respone.startsWith("250")) {
        throw new IOException("250 reply not recieve from serevr");
      }

      // Send DATA command
      pw.println("DATA");
      respone = br.readLine();
      if (!respone.startsWith("354")) {
        throw new IOException("354 reply not recieve from serevr");
      }
      // Send message data
      String messageData = "";
      System.out.println("Enter your message, enter '.' on a seperate line to end message data entry");
      while (true) {
        messageData = key.readLine();
        pw.println(messageData);
        pw.flush();
        if (key.equals(".")) {
          break;
        }
      }
      respone = br.readLine();
      if (!respone.startsWith("250"))
        throw new IOException("250 reply not received from server");

      // Send QUIT command
      pw.println("QUIT");
      pw.flush();

    } catch (IOException e) {
      System.out.println(e);
    }
  }
}