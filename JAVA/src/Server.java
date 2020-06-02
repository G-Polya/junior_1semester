
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
            System.out.println("Connection waiting...");        // 대기중
            socket = listener.accept();                         // 클라이언트와 연결
            System.out.println("Connection completed");
            in = new DataInputStream(socket.getInputStream());
            out = new DataOutputStream(socket.getOutputStream());


            out.writeUTF("Connection completed.");


            out.writeUTF("Input Database name >> ");
            String dbName = in.readUTF();
            System.out.println("dbName : "+dbName);


            Create_Database_Table db = new Create_Database_Table();
            db.CreateOrChangeDatabase(dbName, out);

            out.writeUTF("Input table name >> ");
            String tbName = in.readUTF();
            db.CreateTable(tbName);

            Vector<Integer> sums = new Vector<Integer>();
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


                db.insert_toTable(id,name,attendance,assignment,midterm,finalterm,sum);

            }

            out.writeUTF("Ranking Update...");

            int table_size = db.count_table();
            out.writeInt(table_size);




            for(int i =0 ;i<sums.size();i++)
                System.out.println(db.ranking_func(sums.get(i)));


            db.alter_Table("ranking","int");

            for(int i = 0; i<sums.size();i++)
            {
                int sum = sums.get(i);
                int ranking = db.ranking_func(sum);
                db.update_table("ranking","sum", sum,ranking);
            }

            while(true)
            {
                out.writeUTF("자료를 입력하세요(stop을 입력하면 중지) >> ");
                String data = in.readUTF();
                if(data.equals("stop"))
                    break;

                out.writeUTF("범위의 시작을 입력하세요 >> ");
                int start = in.readInt();

                out.writeUTF("범위의 끝을 입력하세요 >> ");
                int end = in.readInt();

                db.where_between(data,start,end);
            }

            db.select_all();

           // out.flush();

        }
        catch(IOException e)
        {
            e.printStackTrace();
        }


    }
}
