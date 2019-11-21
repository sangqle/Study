import java.io.*;
import java.net.*;

class RequestProcessing extends Thread {
  private Socket s;

  public RequestProcessing(Socket s1) {
    s = s1;
  }

  public void run() {
    try {
      PrintWriter pw = new PrintWriter(s.getOutputStream());
      BufferedReader bw = new BufferedReader(new InputStreamReader(s.getInputStream()));
      String dataInput;
      while (true) {
        dataInput = bw.readLine();
        pw.println(dataInput);
        pw.flush();
        if (dataInput == null || dataInput.equals("quit"))
          break;
      }
      s.close();
    } catch (IOException e) {
      System.err.println("Processing Error: " + e);
    }
  }
}
