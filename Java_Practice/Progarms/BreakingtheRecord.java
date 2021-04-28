import java.util.Scanner;

public class BreakingtheRecord {
    int n,ar[],min,max,min1,max1;


    void GetVal()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("ENter Size");
        n = sc.nextInt();

        ar = new int[n];

        for (int i = 0; i < ar.length; i++) {
            ar[i] = sc.nextInt();
        }
        record();
    }

    void record()
    {
        max = min = ar[0];

        for (int i = 0; i < ar.length; i++) {
            if(max > ar[i])
            {
                max = ar[i];
                max1++;
            }

            if(min < ar[i])
            {
                min = ar[i];
                min1++;
            }
         
        }   
        System.out.println(min1+" "+ max1);
    }
    public static void main(String[] args) {
        BreakingtheRecord b1 = new BreakingtheRecord();
        b1.GetVal();
    }
}
