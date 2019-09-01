package Theory;
public class TypeCasting {
    public static void main(String[] args) {
        System.out.println("(int)(7.9) = " + (int) (7.9));
        System.out.println("(int)(3.3) = " + (int) (3.3));
        System.out.println("(double)(5 + 3)= " + (double) (5 + 3));
        System.out.println("(double)(15)/2= " + ((double) (15) / 2));
        System.out.println("(double)(15/2)= " + ((double) (15 / 2)));
        System.out.println("(int)(7.8 + (double)(15)/2)	= " + ((int)(7.8 + (double) (15) / 2)));
        System.out.println("(int)(7.8 + (double)(15/2))	= " + (double)15 / 2);
        System.out.printf("Phuong trinh co nghiem %.2f",-(float)6/4);
    }
}
