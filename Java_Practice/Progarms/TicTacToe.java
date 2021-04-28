import java.util.Random;
import java.util.Scanner;

public class TicTacToe {
    public static void main(String[] args) {
       
        while(true)
        {
            Scanner sc = new Scanner(System.in);
            TicTac t1 = new TicTac();
            t1.player("player");
            t1.player("cpu");
        }
        
        
    }
}

class TicTac {

    char[][] gameboard = { { ' ', '|', ' ', '|', ' ' },
                             { '-', '+', '-', '+', '-' },
                              { ' ', '|', ' ', '|', ' ' },
                        { '-', '+', '-', '+', '-' }, 
                         { ' ', '|', ' ', '|', ' ' } };

    char symbol;
    Random rand = new Random();

    void changePos(int pos) {
        

        switch (pos) {
        case 1:
            gameboard[0][0] = symbol;
            break;
        case 2:
            gameboard[0][2] = symbol;
            break;
        case 3:
            gameboard[0][4] = symbol;
            break;
        case 4:
            gameboard[2][0] = symbol;
            break;
        case 5:
            gameboard[2][2] = symbol;
            break;
        case 6:
            gameboard[2][4] = symbol;
            break;
        case 7:
            gameboard[4][0] = symbol;
            break;
        case 8:
            gameboard[4][2] = symbol;
            break;
        case 9:
            gameboard[4][4] = symbol;
            break;
        default:
            System.out.println("Enter Valid Postion:");
        }

        for (char[] row : gameboard) {
            for (char c : row) {
                System.out.print(c);
            }
            System.out.println();
        }
    }


    void player(String user)
    {
        int pos;
        if(user.equals("player"))
        {
            symbol = 'X';
        }
        else if(user.equals("cpu"))
        {
            symbol = '0';
        }

        System.out.println("------------------------------------------");

        while(true)
        {
            Scanner sc= new Scanner(System.in);
            System.out.println("Enter Postion from 1 To 9:");
             pos = sc.nextInt();
            
            int cpu = rand.nextInt(9)+1;
            changePos(pos);
        }
    }
}
