import java.io.*;
public class PipedEcho {
    public static void main(String argv[]) {
        try {
            PipedOutputStream cwPipe = new PipedOutputStream();
            PipedInputStream crPipe = new PipedInputStream();
            PipedOutputStream swPipe = new PipedOutputStream(crPipe);
            PipedInputStream srPipe = new PipedInputStream(cwPipe);
            PipedEchoServer server = new PipedEchoServer(srPipe, swPipe);
            PipedEchoClient client = new PipedEchoClient(crPipe, cwPipe);
        } catch(IOException ie) {
            System.out.println("Echo server Error: " + ie);
        }
    }  
}
