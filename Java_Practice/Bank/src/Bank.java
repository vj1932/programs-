/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Scanner;
import java.util.Random;

class Bank {

    String url = "jdbc:mysql://localhost:3306/bank";
    String user = "cool";
    String upass = " cool";
    static int Account_No;
    String Name, pass, Address, Mobile_no, Balance;

    static int randomgenrate() {
        Random r = new Random();
        int numbers = 1000000000 + (int) (r.nextDouble() * 9999999);
        return numbers;
    }

    void transfer_bal() {
        double bal;
        double bal_trasfer, bal_temp;
        int count = 0;
        String acc_no, password;
        String acc_no_tra;
        ResultSet rs, ts;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Account Number:");
        acc_no = sc.nextLine();
        System.out.println("Enter Password:");
        password = sc.nextLine();
        System.out.println("Enter Amout to transfer:");
        bal = sc.nextDouble();
        sc.nextLine();
        System.out.println("Enter transfer Account Number:");
        acc_no_tra = sc.nextLine();

        try {
            Class.forName("com.mysql.jdbc.Driver");
            Connection con = (Connection) DriverManager.getConnection(url, user, upass);
            System.out.println("Connceted");
            Statement st = (Statement) con.createStatement();
            Statement st2 = (Statement) con.createStatement();

            rs = st.executeQuery("select Account_No,pass,Balance from account ;");
            ts = st2.executeQuery("select Account_No,Balance from account;");
            acc_no = (acc_no.trim());
            password = (password.trim());
            acc_no_tra = (acc_no_tra.trim());

            while (rs.next()) {

                if (acc_no.equals(rs.getString("Account_No").trim()) && password.equals(rs.getString("pass").trim())) {

                    while (ts.next()) {

                        String ac;
                        ac = (ts.getString("Account_No").trim());
                        if (acc_no_tra.equals(ac)) {
                            bal_trasfer = Double.parseDouble(ts.getString("Balance"));
                            bal_temp = Double.parseDouble(rs.getString("Balance"));
                            bal_temp = bal_temp - bal;
                            bal_trasfer = bal_trasfer + bal;

                            if (bal_temp <= 500.0) {
                                System.out.println("Sorry You don't have a suffcient balance:");
                                count = 1;
                                con.close();
                                break;
                            } else {
                                String bal_traf = Double.toString(bal_trasfer);
                                String bal_tmp = Double.toString(bal_temp);

                                String s1 = "update account set Balance = ' " + bal_traf + " '  where Account_No = ' " + acc_no_tra + " ';  ";
                                String s2 = "update account set Balance = ' " + bal_tmp + " '  where Account_No = ' " + acc_no + " ';  ";
                                st2.execute(s1);
                                st.execute(s2);
                                System.out.println("SuceessFully trrasfer:");
                                count = 1;
                                con.close();
                                display_details(acc_no, pass);
                                break;
                            }
                        }
                    }
                }

            }

            if (count == 0) {
                System.out.println("Account Not Found:");
            }
        } catch (Exception e) {
//           System.out.println("Something wrong"+e);
        }

    }

    void insert_data() {

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter Name");
        Name = sc.nextLine();
        Name = (Name.trim());

        System.out.println("Enter Balance");
        Balance = sc.nextLine();
        Balance = (Balance.trim());

        System.out.println("Enter Password");
        pass = sc.nextLine();
        pass = (pass.trim());
        System.out.println("Enter address");
        Address = sc.nextLine();
        Address = (Address.trim());

        System.out.println("Enter Mobile no");
        Mobile_no = sc.nextLine();
        Mobile_no = (Mobile_no.trim());

        Account_No = randomgenrate();
        String ACC_TEMP = Integer.toString(Account_No);
        ACC_TEMP = (ACC_TEMP.trim());
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
        } catch (ClassNotFoundException | SQLException e) {
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
            acc_no = acc_no.trim();
            password = password.trim();

            while (rs.next()) {

                String acc = rs.getString("Account_No");
                String pass = rs.getString("pass");

                if (acc_no.equals(rs.getString("Account_No").trim()) && password.equals(rs.getString("pass").trim())) {

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

    void update_data() {
        int count = 0;
        double bal;
        String bal_temp;
        String acc_no, password;
        String acc_no_tra;
        ResultSet rs, ts;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Account Number:");
        acc_no = sc.nextLine();
        acc_no = acc_no.trim();
        System.out.println("Enter Password:");
        password = sc.nextLine();
        password = password.trim();

        try {
            Class.forName("com.mysql.jdbc.Driver");
            Connection con = (Connection) DriverManager.getConnection(url, user, upass);
            System.out.println("Connceted");
            Statement st = (Statement) con.createStatement();
            ResultSet r1;
            String selct = "select * from account ;";
            r1 = st.executeQuery(selct);

            int choice = 0;
            while (r1.next()) {
                if (acc_no.equals(r1.getString("Account_No").trim()) && password.equals(r1.getString("pass").trim())) {
                    while (choice != 5) {
                        System.out.println("Which things to update:");
                        System.out.println("1 For Address");
                        System.out.println("2 For Mobile Number");
                        System.out.println("3 For Password");
                        System.out.println("4 For Name");
                        System.out.println("5 For Exit");
                        choice = sc.nextInt();
                        Statement st1 = (Statement) con.createStatement();
                        switch (choice) {
                            case 1:
                                sc.nextLine();
                                System.out.println("Enter Update Address:");
                                String add = sc.nextLine();
                                int rs1 = st1.executeUpdate("update account set Address = ' " + add + " ' where Account_No = ' " + acc_no + " ' ;");
                                System.out.println("Data Updated:");
                                count = 1;
                                break;
                            case 2:
                                sc.nextLine();
                                System.out.println("Enter Update Mobile_No:");
                                String mob = sc.nextLine();
                                int rs2 = st1.executeUpdate("update account set Mobile_no = ' " + mob + " ' where Account_No = ' " + acc_no + " ' ;");
                                System.out.println("Data Updated:");
                                count = 1;
                                break;
                            case 3:
                                sc.nextLine();
                                System.out.println("Enter Update Password:");
                                String pass = sc.nextLine();
                                int rs3 = st1.executeUpdate("update account set pass = ' " + pass + " ' where Account_No = ' " + acc_no + " ' ;");
                                System.out.println("Data Updated:");
                                count = 1;
                                break;
                            case 4:
                                sc.nextLine();
                                System.out.println("Enter Update Name:");
                                String name = sc.nextLine();
                                int rs4 = st1.executeUpdate("update account set Name = ' " + name + " ' where Account_No = ' " + acc_no + " ' ;");
                                System.out.println("Data Updated:");
                                count = 1;
                                break;
                            case 5:
                                break;

                        }
                    }
                }
            }
        } catch (ClassNotFoundException | SQLException e) {
            System.out.println(e);
        }
        if(count == 0){
            System.out.println("Account or password is incorrect:");
        }
    }

    void deposite() {
        int count = 0;
        String acc_no, pass;
        Double bal;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Account Number:");
        acc_no = sc.nextLine();
        acc_no = acc_no.trim();
        System.out.println("Enter Password:");
        pass = sc.nextLine();
        pass = pass.trim();

        try {
            Class.forName("com.mysql.jdbc.Driver");
            Connection con = (Connection) DriverManager.getConnection(url, user, upass);
            System.out.println("Connceted");
            Statement st = (Statement) con.createStatement();
            ResultSet r1;
            String selct = "select * from account ;";
            r1 = st.executeQuery(selct);
            
            while (r1.next()) {
                if (acc_no.equals(r1.getString("Account_No").trim()) && pass.equals(r1.getString("pass").trim())) {
                    System.out.println("Enter Money To deposite:");
                    bal = sc.nextDouble();
                    String bal_old = (r1.getString("Balance").trim());
                    Double bal_o = Double.valueOf(bal_old);
                    Double bal_temp = bal_o + bal;
                    String bal_update = String.valueOf(bal_temp);
                    int rs2 = st.executeUpdate("update account set Balance= ' " + bal_update + " ' where Account_No = ' " + acc_no + " ' ;");
                    display_details(acc_no, pass);
                    count = 1;
                    break;
                }
            }
        } catch (ClassNotFoundException | SQLException e) {
            System.out.println(e);
            
            if(count == 0){
                System.out.println("Account or password is incorrect");
            }
        }
    }
    
    
    
    void withdraw() {
        String acc_no, pass;
        Double bal;
        
        int count = 0;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Account Number:");
        acc_no = sc.nextLine();
        acc_no = acc_no.trim();
        System.out.println("Enter Password:");
        pass = sc.nextLine();
        pass = pass.trim();

        try {
            Class.forName("com.mysql.jdbc.Driver");
            Connection con = (Connection) DriverManager.getConnection(url, user, upass);
            System.out.println("Connceted");
            Statement st = (Statement) con.createStatement();
            ResultSet r1;
            String selct = "select * from account ;";
            r1 = st.executeQuery(selct);
            
            while (r1.next()) {
                if (acc_no.equals(r1.getString("Account_No").trim()) && pass.equals(r1.getString("pass").trim())) {
                    System.out.println("Enter Money To deposite:");
                    bal = sc.nextDouble();
                    String bal_old = (r1.getString("Balance").trim());
                    Double bal_o = Double.valueOf(bal_old);
                    Double bal_temp = bal_o - bal;
                    if(bal_temp <=500){
                        System.out.println("Can't Withdraw:");
                    }else{
                    String bal_update = String.valueOf(bal_temp);
                    int rs2 = st.executeUpdate("update account set Balance= ' " + bal_update + " ' where Account_No = ' " + acc_no + " ' ;");
                        display_details(acc_no, pass);
                        count = 1;
                    break;
                    }
                }
            }
        } catch (ClassNotFoundException | SQLException e) {
            System.out.println(e);
        }
        
        if(count == 0){
            System.out.println("Account or password is incorrect");
        }
    }
    
    void display_details(String acc_no,String pass){
        int count = 0;
        Double bal;
        Scanner sc = new Scanner(System.in);
        acc_no = acc_no.trim();
        pass = pass.trim();

        try {
            Class.forName("com.mysql.jdbc.Driver");
            Connection con = (Connection) DriverManager.getConnection(url, user, upass);
            System.out.println("Connceted");
            Statement st = (Statement) con.createStatement();
            ResultSet r1;
            String selct = "select * from account ;";
            r1 = st.executeQuery(selct);
            
            while(r1.next()){
                if(acc_no.equals(r1.getString("Account_No").trim()) && pass.equals(r1.getString("pass").trim())){
                    System.out.println("Account_No:"+(r1.getString("Account_No")).trim());
                    System.out.println("Password:"+(r1.getString("pass")).trim());
                    System.out.println("Balance:"+(r1.getString("Balance")).trim());
                    System.out.println("Name:"+(r1.getString("Name")).trim());
                    System.out.println("Address:"+(r1.getString("Address")).trim());
                    System.out.println("Mobile_no:"+(r1.getString("Mobile_no")).trim());
                    count = 1;
                    break;
                }
            }
        }
        catch(ClassNotFoundException | SQLException e){
            System.out.println(e);
        }
        if(count == 0){
            System.out.println("Account or password is incorrect:");
        }
    }
    
    
    void ATM(String acc_no,String pass){
        
        //progress
          try {
            Class.forName("com.mysql.jdbc.Driver");
            Connection con = (Connection) DriverManager.getConnection(url, user, upass);
            System.out.println("Connceted");
            Statement st = (Statement) con.createStatement();
            ResultSet r1;
            String selct = "select * from account ;";
            r1 = st.executeQuery(selct);
            
            while(r1.next()){
                
            }
          }
          catch(ClassNotFoundException | SQLException e){
              System.out.println(e);
          }
    }

}
