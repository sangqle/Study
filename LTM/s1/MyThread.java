import java.io.FileOutputStream;
import java.io.PrintWriter;

public class MyThread extends Thread {
    int name;

    public MyThread(int ten) {
        this.name = ten;
        System.out.println("Thread " + name + " duoc khoi tao ... !");
    }

    public void run() {
        try {
            FileOutputStream f = new FileOutputStream("./out." + this.name);
            PrintWriter pw = new PrintWriter(f);
            for (int i = 0; i < 100; i++) {
                String say = "Hello from " + this.name + "-thread";
                System.out.println(say);
                pw.println(this.name + "-thread");
            }
            pw.flush();
            f.close();
        } catch (Exception e) {
            System.out.println("Loi khi truy xuat file.");
        }

    }

    public static void main(String args[]) {
        if (args.length < 1) {
            System.out.println("Error: Usage n for number of threads.");
            return;
        }
        int nThread = Integer.parseInt(args[0]);
        for (int i = 1; i <= nThread; i++) {
            MyThread th = new MyThread(i);
            th.start();
        }
    }
}