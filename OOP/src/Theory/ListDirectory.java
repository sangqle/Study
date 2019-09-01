
package Theory;

import java.io.File;
import java.io.Serializable;
public class ListDirectory {
    public static void main(String[] args) {
        File dir  = new File("E:\\Web\\CSS");
        listRecursive(dir);
        int i = 1, j = 10;
        do{
            if(i > j)
            {
                break;
            }
            j--;
        }while(++i < 5);
        System.out.println("i = " +  i + " j = " + j);
                
        
    }
    public static void listRecursive(File dir)
    {
        if(dir.isDirectory())
        {
            File [] items = dir.listFiles(); // list file save in item[];
            for(File item : items)
            {
                System.out.println(item.getAbsoluteFile()); // print out absoultute file path
                if(item.isDirectory())
                {
                    listRecursive(item);
                }
            }
        }
    }
    
}
