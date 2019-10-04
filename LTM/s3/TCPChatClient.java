import java.io.*;
import java.net.*;
import java.util.*;

public class TCPChatClient {
    public static void main(String args[]) {
        try {
			// server is listening on port
			if(args.length < 3) {System.out.println("Enter Host Port UserName..."); return;}
			String userName = args[2];
            Socket s = new Socket(args[0], Integer.parseInt(args[1]));
            InputStream is = s.getInputStream();
            OutputStream os = s.getOutputStream();

            BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
			PrintWriter pw = new PrintWriter(s.getOutputStream());
			
			ThreadReader readerFromServer = new ThreadReader(br);
			readerFromServer.start();

			ThreadWritter writterFromClient = new ThreadWritter(pw, userName);
			writterFromClient.start();

        } catch (Exception e) {
            System.out.print(e.toString());
        }
    }
}

class ThreadReader extends Thread
{
	private BufferedReader br;
	public ThreadReader(BufferedReader br) {
    	this.br = br;
	}
	public void run() {
		try {
			while(true) {
				String str = br.readLine();
				System.out.println(str);
			}
		    
		}
		catch (IOException e) {
		  System.err.println("Processing Error: " + e);
		}
	}
}

class ThreadWritter extends Thread
{
	private PrintWriter pw;
	String userName;
	public ThreadWritter(PrintWriter pw, String userName) {
    	this.pw = pw;
		this.userName = userName;
	}
	public void run() {
		try {
			Scanner sc = new Scanner(System.in);
			while(true) {
				String str = sc.nextLine();
				pw.println(userName + ": " + str);
				pw.flush();
			}
		}
		catch (Exception e) {
		  System.err.println("Processing Error: " + e);
		}
	}
}
