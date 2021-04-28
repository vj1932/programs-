import java.util.Scanner;

public class Tictactoe1 {
    public static void main(String[] args) {
        TikTak t1 = new TikTak();
        t1.print();
    }
}

class TikTak{
    
    String s1,s2;
    char symbol,user;
    char[][] gameboard = { { ' ', '|', ' ', '|', ' ' },
                             { '-', '+', '-', '+', '-' },
                              { ' ', '|', ' ', '|', ' ' },
                        { '-', '+', '-', '+', '-' }, 
                         { ' ', '|', ' ', '|', ' ' } };


     Scanner sc = new Scanner(System.in);
    void GetPlayer()
    {
       System.out.println("X Turn is First:");
        
    }






    void print()
    {
        for (char[] row : gameboard) {
            for (char c : row) {
                System.out.print(c);
            }
            System.out.println();
        }
    }
}
