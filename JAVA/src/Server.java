
import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.sql.*;
import java.util.HashMap;
import java.util.Scanner;

import java.sql.*;
import java.util.Vector;


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


            out.writeUTF("Input Database name >> ");
            String dbName = in.readUTF();
            System.out.println("dbName : "+dbName);


            Create_Database_Table db = new Create_Database_Table();
            db.CreateOrChangeDatabase(dbName);

            out.writeUTF("Input table name >> ");
            String tbName = in.readUTF();
            db.CreateTable(tbName);

            Vector<Integer> sums = null;
            while(true)
            {
                out.writeUTF("Input Data(학번, 성명, 출석, 과제, 중간, 기말)");
                String id = in.readUTF();
                if(id.equals("stop"))
                    break;

                String name = in.readUTF();
                int attendance = in.readInt();
                int assignment = in.readInt();
                int midterm = in.readInt();
                int finalterm = in.readInt();
                int sum = attendance + assignment + midterm + finalterm;
                sums.add(sum);

                db.insert_toTable(id,name,attendance,assignment,midterm,finalterm,sum,out);

            }

            int table_size = db.count_table();
            out.writeInt(table_size);
            for(int i = 0; i<sums.size();i++)
                System.out.println(db.ranking_func(sums.get(i)));







            out.flush();

        }
        catch(IOException e)
        {
            e.printStackTrace();
        }


    }
}
