import java.io.*;
public class PipedEchoClient extends Thread {
    PipedInputStream readPipe;
    PipedOutputStream writePipe;
    PipedEchoClient(PipedInputStream readPipe, PipedOutputStream writePipe) {
        this.readPipe = readPipe;
        this.writePipe = writePipe;
        System.out.println("Client creation");
        start();
    }
    public void run() {
        while(true) {
            try {
                int ch = System.in.read();
                writePipe.write(ch);
                ch = readPipe.read();
                System.out.print((char)ch);
            }
            catch(IOException ie) {
                System.out.println("Echo server Error: " + ie);
            }
        }
    }
	  
}
