import java.util.Scanner;

public class GradingStudent {
    int ar[],temp[],size;
     int nextmultiple(int n)
    {
        int flg = n;
        int temp = 1,i = 1;
            while(true)
            {
                temp = 5*i; //30
                if(temp>=n) // 75 >=73
                {
                    break;
                }
                i++;
            }
            temp = temp - n; // 2 = 75 - 73 
            if(temp >= 3) // 2 > = 3
            {
                return n; //73
            }
            else
            {
                n = n + temp; //75 = 73 + 2
                if(n<40) //75 <40
                {
                    n = n - temp;
                    return n;
                }
                else
                {
                    return n;
                }
                
            }
       
        //temp = temp - n < 3 ? n+(temp - n) : n;
        //return temp;
    }
    void getVal()
    {
        Scanner sc = new Scanner(System.in);
        size = sc.nextInt();
        ar = new int[size];
        temp = new int[size];

        for (int i = 0; i < ar.length; i++) {
            ar[i] = sc.nextInt();
        }
        SetVal();
    }

    void SetVal()
    {
    for (int i = 0; i < ar.length; i++) {
        temp[i] = nextmultiple(ar[i]);
    }
    for (int i = 0; i < temp.length; i++) {
      
        System.out.println(temp[i]);
    }
    }

    public static void main(String[] args) {
        GradingStudent g1 = new GradingStudent();
       g1.getVal();
    }
}

