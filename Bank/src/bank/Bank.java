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
    static int Account_No = 100;
    String Name, pass, Address, Mobile_no;

    static int randomgenrate() {
        Random r = new Random();
        int numbers = 1000000000 + (int) (r.nextDouble() * 9999999);
        return numbers;
    }

    void insert_data() {

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter Names");
        Name = sc.nextLine();
        System.out.println("Enter Password");
        pass = sc.nextLine();
        System.out.println("Enter address");
        Address = sc.nextLine();
        System.out.println("Enter Mobile no");
        Mobile_no = sc.nextLine();
        Account_No = randomgenrate();
        try {
            Class.forName("com.mysql.jdbc.Driver");
            Connection con = (Connection) DriverManager.getConnection(url, user, upass);
            System.out.println("Connceted");
            Statement st = (Statement) con.createStatement();

            String s1;
            s1 = "insert into account  values (' " + Account_No + " ' ,  ' " + pass + " ' ,  '" + Name + " ' , '  " + Address + "  ' , '  " + Mobile_no + " '  );";

            st.execute(s1);
//            System.out.println("Acc_no:" + Account_No + "\n" + "Name:" + Name + "\n"
//                       + "pass" + "\n" + pass + "Address" + Address + "\n" + "Number:"
//                        + Mobile_no + "\n");
            System.out.println("Your Account no is:" + Account_No);

        } catch (Exception e) {
            System.out.println(e);
        }

    }

    void delete_data() {
        
        String acc_no, password;
        int count = 0;
        ResultSet  r1 ;
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
            while(rs.next()){
                
               String acc = rs.getString("Account_No");
               String  pass = rs.getString("pass");
               
               System.out.print(rs.getString("Account_No")+",");
               System.out.println(rs.getString("pass")+",");
               
               if(acc.equals(acc_no)) {
                   System.out.println("Get1");
                       if(pass.equals(password)){
                           System.out.println("Get2");
                           System.out.println("Get2");
                           String del = " delete form account where Account =  ' " +acc+" ' ";
                          st.execute(del);
                          count = 1;
               }
               }
            }
            
            if(count == 1){
                System.out.println("Account Delete Suceesfully");
            }
            else
            {
                  System.out.println("Account Not Found");
            }
        }
        catch(Exception e){
            System.out.println(e);
        }

    }

    public static void main(String[] args) {
        Bank b1 = new Bank();
//        b1.insert_data();
        b1.delete_data();
//        String url = "jdbc:mysql://localhost:3306/bank";
//        String user = "cool";
//        String upass = "cool";
//
//        try {
//            Class.forName("com.mysql.jdbc.Driver");
//            Connection con = (Connection) DriverManager.getConnection(url, user, upass);
//            System.out.println("Connceted");
//            Statement st = (Statement) con.createStatement();
//            String s1 = "select * from  account;";
//
//            ResultSet rs = st.executeQuery(s1);
//            while (rs.next()) {
//                String acc_no = rs.getString("Account_No");
//                String name = rs.getString("name");
//                String pass = rs.getString("pass");
//                String add = rs.getString("Address");
//                String mobile_no = rs.getString("Mobile_no");
//
//                System.out.println("Acc_no:" + acc_no + "\n" + "Name:" + name + "\n"
//                        + "pass" + "\n" + pass + "Address" + add + "\n" + "Number:"
//                        + mobile_no + "\n");
//            }
//        } catch (Exception e) {
//            System.out.println(e);
//        }
    }

}
