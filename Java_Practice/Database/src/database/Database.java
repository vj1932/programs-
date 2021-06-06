/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package database;

import com.mysql.jdbc.Connection;
import com.mysql.jdbc.Statement;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;

/**
 *
 * @author Vandit
 */
public class Database {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here

        String url = "jdbc:mysql://localhost:3306/netbeandemo";
        String user = "'cool'";
        String upass = " cool";
        try {
            Class.forName("com.mysql.jdbc.Driver");
            Connection con = (Connection)DriverManager.getConnection(url, user, upass);
            System.out.println("Connceted");
            Statement st = (Statement) con.createStatement();
            String s1 = "select * from  demo;"; 
            
            ResultSet rs = st.executeQuery(s1);
            rs.next();
            String name1 = rs.getString("password");
            System.out.println(name1);
            
        } catch (ClassNotFoundException | SQLException e) {
            System.out.println(e);
        }
    }

}
