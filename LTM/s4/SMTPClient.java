import java.io.*; 
import java.util.*; 
import java.net.*; 

public class SMTPClient {
	public static void main(String[] args) {
		if(args.length < 4) {System.out.println("Enter <server> <port> <mail from> <rcpt to>"); return;}
		 try {
			 String smtpServerName = args[0];
			 int port = Integer.valueOf(args[1]).intValue();
			 
			 Socket smptServerSocket = new Socket(args[0], port);
			 
			 BufferedReader brSmptServerSocket = new BufferedReader(new InputStreamReader(smptServerSocket.getInputStream()));
			 PrintWriter pw = new PrintWriter(smptServerSocket.getOutputStream());
			 BufferedReader keyboard = new BufferedReader(new InputStreamReader(System.in));
			 
			 // helo server
			 pw.println("helo " + smtpServerName);
			 pw.flush();
			 // nhan du lieu tu smpt server gui ve
			 String dataRecive = brSmptServerSocket.readLine();
			 System.out.println("Server Response : " + dataRecive);
			 
			 // mail from
			 pw.println("mail from:" + args[2]);
			 pw.flush();
			 dataRecive = brSmptServerSocket.readLine();
			 System.out.println("Server Response: " + dataRecive);
			 
			 // recipent to mail
			 pw.println("rcpt to:" + args[3]);
			 pw.flush();
			 dataRecive = brSmptServerSocket.readLine();
			 System.out.println("Server Response: " + dataRecive);
			 
			 pw.println("data");
			 pw.flush();
			 dataRecive = brSmptServerSocket.readLine();
			 System.out.println("Server Response: " + dataRecive);
			 
			 // subject
			 System.out.print("subject:");
			 String subjectMail = keyboard.readLine();
			 pw.println("subject:" + subjectMail);
			 pw.flush();
			 dataRecive = brSmptServerSocket.readLine();
			 System.out.println("Server Response: " + dataRecive);
			 
			 // nhap noi dung mail
			 String mailBody;
			 while(true) {
				mailBody = keyboard.readLine();
				if(mailBody.equals(new String("."))) {
					pw.println(".");
					pw.flush();
					break;
				}
				pw.println(mailBody);
			}
			 dataRecive = brSmptServerSocket.readLine();
			 System.out.println("Server Response : " + dataRecive);
			 smptServerSocket.close();
		 } catch(IOException e) {
			 System.out.println(e);
		 }
	}
}