import java.io.*;
import java.net.*;
class RequestProcessing extends Thread
{
  private Socket s;
  public RequestProcessing(Socket s1) {
    s = s1;
  }
  public void run() {
    try {
        OutputStream os = s.getOutputStream();
        InputStream is = s.getInputStream();
        int ch = 0;
        while(true) {
          ch = is.read();
          if(ch == -1) break;
          os.write(ch);
        }
        s.close();
    }
    catch (IOException e) {
      System.err.println("Processing Error: " + e);
    }
  }
}
