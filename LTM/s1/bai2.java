import java.util.*;

public class bai2 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a, b, c: ");

        float a = sc.nextFloat();
        float b = sc.nextFloat();
        float c = sc.nextFloat();

        if (a == 0) {
            if (b == 0) {
                System.out.println("Phương trình vô nghiệm!");
            } else {
                System.out.println("Phương trình có một nghiệm: " + "x = " + (-c / b));
            }
            return;
        }
        // delta
        float delta = b * b - 4 * a * c;
        float x1, x2;
        if (delta > 0) {
            x1 = (float) ((-b + Math.sqrt(delta)) / 2 * a);
            x2 = (float) ((-b - Math.sqrt(delta)) / 2 * a);
            System.out.println("Pt co 2 nghiem: " + "x1 = " + x1 + ", x2 = " + x2);
        } else if (delta == 0) {
            x1 = (-b / 2 * a);
            System.out.println("Pt co nghiem kep: " + "x1 = x2 = " + x1);
        } else {
            System.out.println("Phương trình vô nghiệm!");

        }
    }
}