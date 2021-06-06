import java.io.File;
import java.util.Scanner;

public class FileExa {
    public static void main(String[] args) {
        File f1 = new File("D://Degree/sem4/Java_Practice/Progarms/HelloData.txt");
        try {
            if(f1.exists()){
                System.out.println("Exist:"+f1.getName());
            }
            else{
                f1.createNewFile();
                System.out.println("Created:"+f1.getName());
            }
        } catch (Exception e) {
            System.out.println(e);
            //TODO: handle exception
        }

        try {
            Scanner s = new Scanner(f1);
            while(s.hasNextLine()){
                String str = s.nextLine();
                if (str.equals("Hello")) {
                  continue;
                }else{
                    System.out.println(str);
                }
            }
            
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
