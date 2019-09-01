package Theory;

import java.io.*;

public class FileCopyNoBuffer {

    public static void main(String[] args) {
        String filedoc = "sang.txt";
        String fileghi = "test-write.jpg";
        long batdau, tongtg;
        File f = new File(filedoc);
        System.out.println("Kich thuoc file " + f.length() + "	bytes");
        try {
            FileInputStream in = new FileInputStream(filedoc);
            FileOutputStream out = new FileOutputStream(fileghi);
            batdau = System.nanoTime();
            int ch;
            while ((ch = in.read()) != -1) {
                //System.out.println((char)ch);
                out.write(ch);
                
            }
            tongtg = System.nanoTime() - batdau;
            System.out.println("Thoi gian copy:	" + (tongtg/ 1000000.0) + "ms");
}
catch (IOException ex) {
            ex.printStackTrace();
        }
    }
}
