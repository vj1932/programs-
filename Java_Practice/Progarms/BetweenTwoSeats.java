import java.util.Scanner;

public class BetweenTwoSeats {
    int arr1[] = {2,4},arr2[]={24,36},size1,size2,temp[] = new int[10],temp2[] = new int[10];

    // void GetVal()
    // {
    //     Scanner sc = new Scanner(System.in);
    //     System.out.println("Enter Size one");
    //     size1 = sc.nextInt();
    //     System.out.println("Enter Size two");
    //     size2 = sc.nextInt();
    //     arr1 = new int[size1];
    //     arr2 = new int[size2];
    //     temp = new int[size1+size2];

    //     for (int i = 0; i < arr1.length; i++) {
    //         System.out.println("Enter Element:");
    //         arr1[i] = sc.nextInt();
    //     }

    //     for (int i = 0; i < arr2.length; i++) {
    //         System.out.println("Enter Element:");
    //         arr2[i] = sc.nextInt();
    //     }

    //     nextMultiple();
    // }

    void nextMultiple()
    {
        int flg = 1, flg1 = 1,j=1;
        for (int i = 0; i < arr1.length; i++) {
            flg = arr1[i]*j;
            for ( j = 1; j <= 10; j++) {    
                flg1 = arr1[i+1]*j;
                if(flg == flg1)
                    {
                        temp[j] = flg1;
                    }
                
            }
        }

        for (int i = 0; i < arr1.length; i++) {
            System.out.println(temp[i]);
        }
    }


    public static void main(String[] args) {
        BetweenTwoSeats b1 = new BetweenTwoSeats();
        b1.nextMultiple();
    }
}
