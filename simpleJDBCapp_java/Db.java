import java.sql.*;
import java.util.Scanner;

public class Db {

    static final String DRIVER = "oracle.jdbc.driver.OracleDriver";
    static final String URL = "jdbc:oracle:thin:@hostname:port:sid";
    static final String USER = "username";
    static final String PASSWORD = "password";
        
    public static void main (String[] args) {

        System.out.println("Connecting...");

        Scanner scanner = new Scanner(System.in);
        int input = 0;
        Connection conn = null;
        Statement statement = null;
        try {
            Class.forName(DRIVER); //Register driver
            conn = DriverManager.getConnection(URL,USER,PASSWORD); 

            System.out.println("Connected!");
            System.out.println("1 - Print Items. 2 - Print customers. -1 Exit");

            while (input != -1) {
            System.out.print(">");
            input = scanner.nextInt();
                switch (input){
                    case 1:
                        printItems(statement, conn);
                        break;
                    case 2:
                        printCustomers(statement, conn);
                        break;
                    case -1:
                        System.out.println("Exiting");
                        break;
                    default:
                        System.out.println("Invalid input");
                        break;
                }
                
            }

        } catch (SQLException e) {
            throw new Error ("Couldn't connect\nProblem", e);
        }  catch (ClassNotFoundException ex) {
            System.out.println("Class not found" + ex);

        } finally {
            try {
                if (conn != null)
                    conn.close();
            } catch (SQLException se) {
                se.printStackTrace();
            }

        }
        System.out.println("Connection closed.");

    }

    static void printItems (Statement statement, Connection conn) {
        try {
        statement = conn.createStatement();

        String query = "SELECT * FROM t_items";
        ResultSet result = statement.executeQuery(query);
        System.out.println("ID\tTitle");
        System.out.println("-------------");
        while(result.next()) {
            int id = result.getInt("id");
            String title = result.getString("title");
            System.out.println(id + " - " + title);
        }
        result.close();
        } catch (SQLException ex) {
            ex.printStackTrace();
        }

    }

    static void printCustomers (Statement statement, Connection conn) {
        try {
        statement = conn.createStatement();

        String query = "SELECT * FROM t_customers";
        ResultSet result = statement.executeQuery(query);
        System.out.println("ID\tName\tE-mail");
        System.out.println("------------------");
        while(result.next()) {
            int id = result.getInt("id");
            String name= result.getString("name");
            String email= result.getString("email");
            System.out.println(id + " - " + name + " - " + email);
        }
        result.close();
        } catch (SQLException ex) {
            ex.printStackTrace();
        }

    }


}
