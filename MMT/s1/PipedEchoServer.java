import java.io.*;
public class PipedEchoServer extends Thread {
    PipedInputStream readPipe;
    PipedOutputStream writePipe;
    PipedEchoServer(PipedInputStream readPipe, PipedOutputStream writePipe) {
        this.readPipe = readPipe;
        this.writePipe = writePipe;
        System.out.println("Server is starting...");
        start();
    }
    public void run() {
        while(true) {
            try {
                int ch = readPipe.read();
                writePipe.write(ch);
            }
            catch(IOException ie) {
                System.out.println("Echo server Error: " + ie);
            }
        }
    }
	  
}
