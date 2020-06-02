
import java.io.*;
import java.net.Socket;
import java.nio.Buffer;
import java.sql.*;
import java.util.HashMap;
import java.util.Scanner;
import java.util.Vector;


public class Client
{


    public static void main(String[] args)
    {
        DataInputStream in = null;
        DataOutputStream out = null;
        Socket socket = null;
        Scanner scanner = new Scanner(System.in);

        try
        {
            socket = new Socket("localhost",9999);
            in = new DataInputStream(socket.getInputStream());      // 들어오는 데이터
            out = new DataOutputStream(socket.getOutputStream());   // 나가는 데이터ㅋ
            System.out.println("Sever says : "+in.readUTF());

            System.out.println("Server says : "+in.readUTF());      // Input database name >>
            String dbName = scanner.next();
            out.writeUTF(dbName);                                   // 서버로 전송

            System.out.println("Server says : "+in.readUTF());      // Input tablename name >>
            String tbName = scanner.next();
            out.writeUTF(tbName);


            // 자료 입력
            Vector<Integer> ids = new Vector<>();
            boolean flag = true;
            while(flag)
            {
                System.out.println("Server says : "+in.readUTF());      // Input data
                String id = scanner.next();
                Integer temp_id = Integer.parseInt(id);
                System.out.println("id : "+id);
                out.writeUTF(id);
                for(int i = 0 ;i < ids.size();i++)
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

                ids.add(temp_id);      //ids에 id와 같은 게 없으면 add
                if(id.equals("stop"))
                    break;

    //            System.out.println("Server says : "+in.readUTF());
                String name = scanner.next();
                out.writeUTF(name);

    //            System.out.println("Server says : "+in.readUTF());
                int attendance = scanner.nextInt();
                out.writeInt(attendance);

  //              System.out.println("Server says : "+in.readUTF());
                int assignment = scanner.nextInt();
                out.writeInt(assignment);

      //          System.out.println("Server says : "+in.readUTF());
                int midterm = scanner.nextInt();
                out.writeInt(midterm);

         //       System.out.println("Server says : "+in.readUTF());
                int finalterm = scanner.nextInt();
                out.writeInt(finalterm);



                System.out.println("Server says : "+in.readUTF());


                // out.flush();

            }

            System.out.println("Server says : "+in.readUTF());      // Ranking Update...
            System.out.println("Server says : "+in.readUTF());      // The number of rows ...

            int table_size = in.readInt();

            System.out.println("Server says : "+in.readUTF());      // Alter complete or Alter Error


            for(int i =0;i<table_size;i++)
            {
                System.out.println("Server says : "+in.readUTF());      // update table or update error

            }

            while(true)
            {
                System.out.println("Server says : "+in.readUTF());   // 자료를 입력하세요
                String data = scanner.next();
                out.writeUTF(data);
                if(data.equals("stop"))
                    break;

                System.out.println("Server says : "+in.readUTF());   // 범위의 시작을 입력하세요
                int start = scanner.nextInt();
                out.writeInt(start);

                System.out.println("Server says : "+in.readUTF());   // 범위의 끝을 입력하세요
                int end = scanner.nextInt();
                out.writeInt(end);

                int count = in.readInt();
                for(int i = 0; i < count;i++)
                    System.out.println("Server says : "+in.readUTF());          // start와 end 사이에는 ...
            }


            int count = in.readInt();
            System.out.println("Server says : "+in.readUTF());
            for(int i = 0; i< count;i++)
                System.out.println("Server says : "+in.readUTF());              // 테이블 전체출력



        }
        catch(IOException e)
        {
            e.printStackTrace();
        }
    }
}
