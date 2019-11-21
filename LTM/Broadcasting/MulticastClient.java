import java.io.*;
import java.net.*;
import java.util.*;

public class MulticastClient {

  public static void main(String[] args) throws IOException {
    if (args.length < 1) {
      System.out.println("Usage: <userName>.");
      return;
    }

    MulticastSocket socket = new MulticastSocket(4446);
    InetAddress address = InetAddress.getByName("230.0.0.1");
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    socket.joinGroup(address);

    ThreadReader reader = new ThreadReader(socket);
    ThreadWritter writter = new ThreadWritter(socket, address, args[0], br);
    reader.start();
    writter.start();

    // socket.leaveGroup(address);
    // socket.close();
  }

}

// ClientHandler clasS
class ThreadReader extends Thread {
  private MulticastSocket socket;

  public ThreadReader(MulticastSocket s1) {
    this.socket = s1;
  }

  public void run() {
    DatagramPacket packet;

    try {
      while (true) {
        byte[] buf = new byte[256];
        packet = new DatagramPacket(buf, buf.length);

        socket.receive(packet);

        String received = new String(packet.getData(), 0, packet.getLength());
        System.out.println(received);
      }

    } catch (IOException e) {
      System.err.println("Processing Error: " + e);
    }
  }
}

class ThreadWritter extends Thread {
  private InetAddress address;
  private MulticastSocket socket;
  private BufferedReader br;
  private String userName;

  public ThreadWritter(MulticastSocket s1, InetAddress address, String userName, BufferedReader br) {

    this.socket = s1;
    this.address = address;
    this.userName = userName;
    this.br = br;
  }

  public void run() {
    try {
      DatagramPacket packetSend;
      String message;
      while (true) {
        byte[] bufSend = new byte[256];
        message = br.readLine();
        message = this.userName + ": " + message;
        bufSend = message.getBytes();
        packetSend = new DatagramPacket(bufSend, bufSend.length, address, 4446);
        socket.send(packetSend);
      }
    } catch (Exception e) {
      System.err.println("Processing Error: " + e);
    }
  }
}
