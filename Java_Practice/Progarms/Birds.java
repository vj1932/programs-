import java.util.*;

public class Birds{
    
    int[] arr;
    public int count=0;
    int maxone,size;
    int temp[];

    Birds(){
        System.out.println("Enter Size:");
        Scanner sc = new Scanner(System.in);
        size = sc.nextInt();
        arr = new int[size];

        for (int i = 0; i < size; i++) {
            System.out.println("Enter Element:");
            arr[i] = sc.nextInt();
        }
    }

    void max(){
         maxone = arr[0];
        for (int i = 0; i < arr.length; i++) {
            if(maxone < arr[i]){
                maxone = arr[i];
            }
        }
    }


    void set(){
        temp = new int[maxone+1];
        for (int i : arr) {
            temp[i]+=1;
        }
        int max = temp[0];
        int ind = 0;
        for (int i = 0; i < temp.length; i++) {
            if(max < temp[i]){
                max = temp[i];
                ind = i;
            }
        }

        System.out.println(ind);
    }
    public static void main(String[] args) {
        Birds n1 = new Birds();
        n1.max();
        n1.set();
        
    }
}