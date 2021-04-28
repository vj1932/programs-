import java.util.Scanner;

public class OneLineJum {
    int x1,v1,x2,v2;
    void GetVal()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter First Starting Postion:");
        x1 = sc.nextInt();
        System.out.println("Enter rate :");
        v1 = sc.nextInt();
        System.out.println("Enter Second Starting Postion:");
        x2 = sc.nextInt();
        System.out.println("Enter rate :");
        v2 = sc.nextInt();
    }
    void Jump()
    {
        int i=x1,j=x2;
        String temp1 = "NO";
        
            for (int k = 0; k < 100000; k++) {
                i = i + v1;
                j = j + v2;
                if(i == j)
                {
                    temp1 = "YES";
                    break;
                }
            }
       
       
       System.out.println(temp1);
    }
 public static void main(String[] args) {
    OneLineJum o1 = new OneLineJum();
    o1.GetVal();
    o1.Jump();
 }   
}