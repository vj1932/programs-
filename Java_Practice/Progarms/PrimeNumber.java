public class PrimeNumber {
    public static void main(String[] args) {

        teststatic t1 = new teststatic();
        t1.helo();
    }
}

class teststatic{
      int a[] ={1,2,3,4,5};
      int temp = 0,i = 0;
     void helo()
    {
       if(i != 5)
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
        helo();
    }
   
}
