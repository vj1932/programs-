import java.util.Scanner;

public class StarCase{
    public static void main(String[] args) {
        int i,n = 0,s = 0,pattern = 0,j;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Number:");
        n = sc.nextInt();
        for(i = 0; i < n; i++)
        {
            s = n - (i+1);
            for(j = 0; j < s; j++)
            {
                System.out.print(" ");
            }
            pattern = i + 1;
      
            for(j = 0; j < pattern; j++)
            {
                System.out.print("#");
            }
            System.out.println();
        }
    }        
    }


