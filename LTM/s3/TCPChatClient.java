import java.io.*;
import java.net.*;
import java.util.*;

public class TCPChatClient {
	public static void main(String args[]) {
		try {
			// server is listening on port
			if (args.length < 3) {
				System.out.println("Enter Host Port UserName...");
				return;
			}
			String userName = args[2];
			Socket s = new Socket(args[0], Integer.parseInt(args[1]));

			BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
			PrintWriter pw = new PrintWriter(s.getOutputStream());

			ThreadReader readerFromServer = new ThreadReader(s, br);
			readerFromServer.start();

			ThreadWritter writterFromClient = new ThreadWritter(s, pw, userName);
			writterFromClient.start();

		} catch (Exception e) {
			System.out.print(e.toString());
		}
	}
}