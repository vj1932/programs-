import java.util.Arrays;

public class String1 {
    public static void main(String[] args) {
        testString t1 = new testString();
        t1.Print();
    }
}
class testString{
    String s1 = "the a hello";

    void Print()
    {
        char[] c1 = s1.toCharArray();
        System.out.println(c1);
         
        for (int i = 0; i < c1.length; i++) {
            if(c1[i] == ' ')
            {
                c1[i] = '0';
            }
        }
        System.out.println(c1);
    }

   
}
