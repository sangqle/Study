/**
 * EagerInitializedSingleton
 */
public class EagerInitializedSingleton {
    String mssv, name;
    private static EagerInitializedSingleton instance;

    // private construtor to avoid client application to use constructure
    private EagerInitializedSingleton() {
        this.name = "Le Quang sang";
        this.mssv = "B1606927";
    }

    public static EagerInitializedSingleton getInstance() {
        if (instance == null) {
            instance = new EagerInitializedSingleton();

        }
        return instance;
    }

    // public static void main(String[] args) {
    // EagerInitializedSingleton a = new EagerInitializedSingleton();
    // System.out.println(a.getInstance().mssv);
    // }
}

class Test {
    public static void main(String[] args) {

        EagerInitializedSingleton a = EagerInitializedSingleton.getInstance();
        System.out.println(a.name);
    }

}