import java.io.*; 
import java.util.*; 
import java.net.*; 
  
// Server class 
public class TCPChatServer  
{ 
    public static void main(String[] args) throws IOException  
    { 
		// server is listening on port
		if(args.length < 2) {System.out.println("Enter PORT UserName..."); return;}
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
		        ThreadReader readerFromClient = new ThreadReader(br);
				readerFromClient.start();
				ThreadWritter writterFromServer = new ThreadWritter(pw, userName);
				writterFromServer.start();

        	}
		} catch (Exception e) {
			System.out.println(e);
		}
    } 
} 
  
// ClientHandler clasS
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
