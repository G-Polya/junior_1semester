
import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.sql.*;
import java.util.Scanner;

import java.sql.*;


public class Server
{
    public static void main(String[] args)
    {
        DataInputStream in = null;
        DataOutputStream out = null;
        ServerSocket listener = null;
        Socket socket = null;
        Scanner scanner = new Scanner(System.in);

        try
        {
            listener = new ServerSocket(9999);
            System.out.println("Connection waiting...");
            socket = listener.accept();
            System.out.println("Connection completed");
            in = new DataInputStream(socket.getInputStream());
            out = new DataOutputStream(socket.getOutputStream());
            out.writeUTF("Connection completed.");


//            out.writeUTF("Input password >> ");
//            String password = in.readUTF();

            out.writeUTF("Input Database name >> ");
            String dbName = in.readUTF();
            System.out.println("dbName : "+dbName);


            Create_Database_Table db = new Create_Database_Table();
            db.CreateOrChangeDatabase(dbName);

            out.flush();

        }
        catch(IOException e)
        {
            e.printStackTrace();
        }


    }
}
