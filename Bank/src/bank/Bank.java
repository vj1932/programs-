/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Bank;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Scanner;
import java.util.Random;

public class Bank {

    String url = "jdbc:mysql://localhost:3306/bank";
    String user = "cool";
    String upass = "cool";
    static int Account_No;
    String Name, pass, Address, Mobile_no, Balance;

    static int randomgenrate() {
        Random r = new Random();
        int numbers = 1000000000 + (int) (r.nextDouble() * 9999999);
        return numbers;
    }

    
    
    void transfer_bal(){
        double bal;
        String acc_no,password,acc_no2;
        
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Account Number:");
        acc_no = sc.nextLine();
        System.out.println("Enter Password:");
        password = sc.nextLine();
        System.out.println("Enter Amout to transfer:");
        bal = sc.nextDouble();
         System.out.println("Enter transfer Account Number:");
        acc_no2 = sc.nextLine();
        
        
        
           try {
            Class.forName("com.mysql.jdbc.Driver");
            Connection con = (Connection) DriverManager.getConnection(url, user, upass);
            System.out.println("Connceted");
            Statement st = (Statement) con.createStatement();

            ResultSet rs = st.executeQuery(" select Account_No,pass,Balance from account");
            ResultSet ts = st.executeQuery(" select Account_No,Balance from account");
            acc_no = acc_no.trim();
            password = password.trim();

            while (rs.next()) {
                
                if(acc_no.equals(rs.getString("Account_No").trim()) && password.equals(rs.getString("pass").trim())){
                    
                    while(ts.next()){
                        if(acc_no2.equals(ts.getString("Account_No").trim()))
                        {
                            double bal_trasfer = Double.parseDouble(ts.getString(Balance));
                            double bal_temp = Double.parseDouble(rs.getString(Balance));
                            bal_trasfer = bal_temp - bal;
                            
                            if(bal_temp <=500){
                                
                                bal_trasfer = bal_trasfer - bal;
                                bal_temp = bal_temp + bal;
                                System.out.println("Sorry Ypu don't have a suffcient balance:");
                            }
                        }
                    }
                    
                }
                
            }
           }
           catch(ClassNotFoundException | SQLException e){
               System.out.println(e);
           }
   
        
    }
    
    
    void insert_data() {

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter Names");
        Name = sc.nextLine();
        System.out.println("Enter Balance");
        Balance = sc.nextLine();
        System.out.println("Enter Password");
        pass = sc.nextLine();
        System.out.println("Enter address");
        Address = sc.nextLine();
        System.out.println("Enter Mobile no");
        Mobile_no = sc.nextLine();
        Account_No = randomgenrate();
        String ACC_TEMP = Integer.toString(Account_No);
        try {
            Class.forName("com.mysql.jdbc.Driver");
            Connection con = (Connection) DriverManager.getConnection(url, user, upass);
            System.out.println("Connceted");
            Statement st = (Statement) con.createStatement();

            String s1;
            s1 = "insert into account  values (' " + ACC_TEMP + " ' ,  ' " + pass + " ' ,' " + Balance + " ', ' " + Name + " ' , '  " + Address + "  ' , '  " + Mobile_no + " '  );";

            st.execute(s1);
//            System.out.println("Acc_no:" + Account_No + "\n" + "Name:" + Name + "\n"
//                       + "pass" + "\n" + pass + "Address" + Address + "\n" + "Number:"
//                        + Mobile_no + "\n");
            System.out.println("Your Account no is:" + ACC_TEMP);

        } catch (Exception e) {
            System.out.println(e);
        }

    }

    void delete_data() {

        String acc_no, password;
        int count = 0;
        ResultSet r1;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Account No:");
        acc_no = sc.nextLine();
        System.out.println("Enter Password");
        password = sc.nextLine();

        try {
            Class.forName("com.mysql.jdbc.Driver");
            Connection con = (Connection) DriverManager.getConnection(url, user, upass);
            System.out.println("Connceted");
            Statement st = (Statement) con.createStatement();

            ResultSet rs = st.executeQuery(" select Account_No,pass from account");
            System.out.println("User:");
            acc_no = acc_no.trim();
            password = password.trim();

            while (rs.next()) {

                String acc = rs.getString("Account_No");
                String pass = rs.getString("pass");

                if (acc_no.equals(rs.getString("Account_No").trim()) && password.equals(rs.getString("pass").trim())) {
                    System.out.println("Get1");
                    System.out.println("Get2");
                    System.out.println("Get2");

                    String del = " delete from account where Account_No =  ' " + acc_no + " ' ";
                    st.execute(del);
                    count = 1;
                    break;
                }
            }

            if (count == 1) {
                System.out.println("Account Delete Suceesfully");
            } else {
                System.out.println("Account Not Found");
            }
        } catch (Exception e) {
            System.out.println(e);
        }

    }

    public static void main(String[] args) {
        Bank b1 = new Bank();
        Scanner sc = new Scanner(System.in);
        int choice = 0;
        System.out.println("Enter Choice:");
        
        
        while(choice!=3){
            System.out.println("Press 1 For Create Account");
            System.out.println("Press 2 For  Delete Account");
            System.out.println("Press 3 For Exit");
            choice = sc.nextInt();
            switch(choice){
                
                case 1:
                    b1.insert_data();
                    break;
                case 2:
                    b1.delete_data();
                    break;
                case 3:
                    break;
            }
        }

    }

}
