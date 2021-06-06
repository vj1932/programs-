
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author Vandit
 */
public class Bank2 extends Bank {

    public static void main(String[] args) {
        Bank b1 = new Bank();
        Scanner sc = new Scanner(System.in);
        int choice = 0;
        System.out.println("Enter Choice:");

        while (choice != 8) {
            System.out.println("Press 1 For Create Account:");
            System.out.println("Press 2 For  Delete Account:");
            System.out.println("Press 3 For Transfer Money: ");
            System.out.println("Press 4 For Update:");
            System.out.println("Press 5 for deposite Money:");
            System.out.println("Press 6 for WithDraw Money:");
            System.out.println("Press 7 for View Details:");
            System.out.println("Press 8 for Exit:");
            choice = sc.nextInt();
            switch (choice) {
                case 1:
                    b1.insert_data();
                    break;
                case 2:
                    b1.delete_data();
                    break;
                case 3:
                    b1.transfer_bal();
                    break;
                case 4:
                    b1.update_data();
                    break;
                case 5:
                    b1.deposite();
                    break;
                case 6:
                    b1.withdraw();
                    break;
                case 7:
                    sc.nextLine();
                    System.out.println("Enter Account No:");
                    String acc_no = sc.nextLine();
                    System.out.println("Enter Password No:");
                    String pass = sc.nextLine();
                    b1.display_details(acc_no, pass);
                case 8:
                    break;
            }
        }
    }
}
