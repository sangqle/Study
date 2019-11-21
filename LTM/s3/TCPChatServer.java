import java.io.*;
import java.util.*;
import java.net.*;

// Server class 
public class TCPChatServer {
	public static void main(String[] args) throws IOException {
		// server is listening on port
		if (args.length < 2) {
			System.out.println("Enter PORT UserName...");
			return;
		}
		int port = Integer.valueOf(args[0]).intValue();
		ServerSocket ss = new ServerSocket(port);

		Socket s;
		String userName = args[1];
		try {
			while (true) {
				s = ss.accept();

				System.out.println("New client request received : " + s);

				// obtain input and output streams
				BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
				PrintWriter pw = new PrintWriter(s.getOutputStream());

				System.out.println("Creating a new handler for this client...");

				// Create a new handler object for handling this request.
				ThreadReader readerFromClient = new ThreadReader(s, br);
				readerFromClient.start();
				ThreadWritter writterFromServer = new ThreadWritter(s, pw, userName);
				writterFromServer.start();

			}
		} catch (Exception e) {
			System.out.println(e);
		}
	}
}

// ClientHandler clasS
class ThreadReader extends Thread {
	private BufferedReader br;
	private Socket s;

	public ThreadReader(Socket s1, BufferedReader br) {
		this.s = s1;
		this.br = br;
	}

	public void run() {
		try {
			while (true) {
				String str = br.readLine();
				if (str == null) {
					s.close();
					break;
				}
				System.out.println(str);
			}

		} catch (IOException e) {
			System.err.println("Processing Error: " + e);
		}
	}
}

class ThreadWritter extends Thread {
	private PrintWriter pw;
	String userName;
	private Socket s;

	public ThreadWritter(Socket s1, PrintWriter pw, String userName) {
		this.s = s1;
		this.pw = pw;
		this.userName = userName;
	}

	public void run() {
		try {
			Scanner sc = new Scanner(System.in);
			while (true) {
				String str = sc.nextLine();
				if (str == null) {
					s.close();
					break;
				}
				pw.println(userName + ": " + str);
				pw.flush();
			}
		} catch (Exception e) {
			System.err.println("Processing Error: " + e);
		}
	}
}
