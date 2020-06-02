
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


            out.writeUTF("Input Database name >> ");        // 클라이언트쪽에 데이터베이스 입력하라고 전송
            String dbName = in.readUTF();                       // 클라이언트로부터 온 dbName 저장
            System.out.println("dbName : "+dbName);


            Create_Database_Table db = new Create_Database_Table();
            db.CreateOrChangeDatabase(dbName, out);     //데이터베이스 생성

            out.writeUTF("Input table name >> ");
            String tbName = in.readUTF();
            db.CreateTable(tbName);                     // 테이블 생성

            Vector<Integer> sums = new Vector<Integer>();   // ranking계산을 위한 sums
            Vector<Integer> ids = new Vector<>();
            boolean flag = true;
            while(flag)         // 자료 입력 부분
            {
                out.writeUTF("자료를 입력하세요(학번, 이름, 출석, 과제, 중간, 기말)>> ");
                String id = in.readUTF();
                System.out.println("id : "+id);
                if(id.equals("stop"))       // stop 입력하면 종료
                {
                    System.out.println("입력 종료");
                    break;
                }
                Integer temp_id = Integer.parseInt(id);
                for(int i = 0; i<ids.size();i++)
                    if(ids.get(i) == temp_id)
                    {
                        flag = false;
                        System.out.println("Primary key Error");

                        break;
                    }

                if(flag == false)
                {
                    flag = true;
                    continue;
                }


                ids.add(temp_id);



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

            db.alter_Table("ranking","int");



            for(int i = 0; i<sums.size();i++)
            {
                int sum = sums.get(i);
               // System.out.println("sum : "+sum+", i : "+i);
                int ranking = db.ranking_func(sum);
                db.update_table("ranking","sum", sum,ranking);
            }

            // 자료 select
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
