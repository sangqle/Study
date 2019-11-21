import java.io.*;
import java.net.*;
import java.util.*;
import java.lang.*;

public class MulticastServerThread extends Thread {
  private DatagramSocket socket = null;

  public MulticastServerThread() throws IOException {
    this.socket = new DatagramSocket(4445);
  }

  public void run() {
    while (true) {
      try {
        byte[] buf = new byte[256];
        // send it
        InetAddress group = InetAddress.getByName("230.0.0.1");

        DatagramPacket packet = new DatagramPacket(buf, buf.length, group, 4446);
        socket.receive(packet);
        socket.send(packet);
      } catch (IOException e) {
        e.printStackTrace();
      }
    }
    // socket.close();
  }
}