import java.io.*;
import java.util.*;
import java.net.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class POPClient {
    public static void main(String[] args) {
        if (args.length < 4) {
            System.out.println("Enter <server> <port> <user> <password>");
            return;
        }
        try {

            String pop3ServerName = args[0];
            int port = Integer.valueOf(args[1]).intValue();

            // create socket
            Socket pop3ServerSocket = new Socket(pop3ServerName, port);

            BufferedReader brPop3ServerSocket = new BufferedReader(
                    new InputStreamReader(pop3ServerSocket.getInputStream()));
            PrintWriter pw = new PrintWriter(pop3ServerSocket.getOutputStream());
            BufferedReader keyboard = new BufferedReader(new InputStreamReader(System.in));

            String dataRecive = brPop3ServerSocket.readLine();
            System.out.println("Server Response : " + dataRecive);

            // Login
            pw.println("user " + args[2]);
            pw.flush();
            dataRecive = brPop3ServerSocket.readLine();
            System.out.println("Server Response : " + dataRecive);
            pw.println("pass " + args[3]);
            pw.flush();
            dataRecive = brPop3ServerSocket.readLine();
            System.out.println("Server Response: " + dataRecive);

            // recive a email with number
            String noMail = "1";
            while (true) {
                System.out.println("Enter message no: <number>, '0' for the end, 'inbox' for the last email: ");
                noMail = keyboard.readLine();

                if (noMail.equals("0")) {
                    pw.println("QUIT");

                    pw.flush();
                    break;
                }

                if (noMail.equals("inbox")) {
                    pw.println("stat");
                    pw.flush();
                    dataRecive = brPop3ServerSocket.readLine();
                    System.out.println(dataRecive);
                    Pattern p = Pattern.compile("\\d+");
                    Matcher numberOfMail = p.matcher(dataRecive);
                    if (numberOfMail.find()) {
                        pw.println("retr " + numberOfMail.group());
                        pw.flush();
                    }
                } else {
                    pw.println("retr " + noMail);
                    pw.flush();
                }

                // read email
                while (true) {
                    dataRecive = brPop3ServerSocket.readLine();
                    if (dataRecive.equals("-ERR There's no message " + noMail + ".")) {
                        System.out.println("-ERR There's no message " + noMail + ".");
                        break;
                    }
                    System.out.println(dataRecive);
                    if (dataRecive.equals(".")) {
                        break;
                    }
                }
            }
            pop3ServerSocket.close();
        } catch (IOException e) {
            System.out.println(e);
        }
    }
}