package Game;


import java.util.Scanner;
import java.io.*;

public class Game {
    public static void main(String[] args){
        Cuop Cuop001;
        ToaDo m = new ToaDo(200,200);
        Cuop001 = new Cuop("Cuop 001",m,50,100,"Mo Khoa");
        Cuop001.hienthi();
        Scanner kb = new Scanner(System.in);
        System.out.println("Nhap so luong Nhan vat can them vao: ");
        int n= kb.nextInt();
        Cuop ds[]= new Cuop[n];
        for (int i=0;i<n;i++){
         ds[i]=new Cuop();
         ds[i].nhap();
        }
        
        try {
            ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("save1.bin"));
            for (int i=0;i<n;i++)
                {
                    oos.writeObject(ds[i]);
                }
            
            oos.flush(); // đẩy nó vô
            oos.close();
        } catch (IOException e) {
            System.out.println("ERROR ghi file");
        }
        Cuop dsin[]= new Cuop[n];
            
        try {
            FileInputStream f = new FileInputStream("save1.bin");
            ObjectInputStream ois = new ObjectInputStream(f);
            for (int i=0;i<n;i++){
             dsin[i]=null;
             dsin[i]= new Cuop();
             dsin[i]= (Cuop) ois.readObject();
             }
            ois.close();
        } catch (ClassNotFoundException e){
            System.out.println("ERROR CLASS");
        } catch (IOException e){
            System.out.println("ERROR xuat file");
        }
        for (int i=0;i<n;i++){
            dsin[i].hienthi();
        }
}
}