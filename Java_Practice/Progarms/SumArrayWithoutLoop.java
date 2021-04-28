import java.util.Scanner;

public class SumArrayWithoutLoop {
    public static void main(String[] args) {
        SumArr s1 = new SumArr();
        s1.getVal();
        s1.Check();
    }
}
class SumArr{
    int a[];
    int temp = 0,i = 0,size;

    void getVal()
    {
        System.out.println("Enter Size");
        Scanner sc = new Scanner(System.in);
        size = sc.nextInt();
        a = new int[size];
        for (int i = 0; i < a.length; i++) {
            System.out.println("Enter Element:");
            a[i] = sc.nextInt();
        }
    }
   void Check()
    {
     if(i != size)
     {
        
        print();
     }
     else
     {
         System.out.println(temp);
         return;
     }

     
  }

  void print()
  {
      temp = a[i]+ temp;
      i++;
      Check();
  }
 
}