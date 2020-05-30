
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
            in = new DataInputStream(socket.getInputStream());
            out = new DataOutputStream(socket.getOutputStream());
            String inputMessage = in.readUTF();
            System.out.println("Sever says : "+inputMessage);

//            System.out.println("Server says : "+in.readUTF());      // Input user name >>
//            String username = scanner.next();
//            out.writeUTF(username);


//            System.out.println("Server says : "+in.readUTF());      // Input password >>
//            String password = scanner.next();
//            out.writeUTF(password);

            System.out.println("Server says : "+in.readUTF());      // Input database name >>
            String dbName = scanner.next();
            out.writeUTF(dbName);

            System.out.println("Server says : "+in.readUTF());      // Input tablename name >>
            String tbName = scanner.next();
            out.writeUTF(tbName);


            // 자료 입력
            while(true)
            {
                System.out.println("Server says : "+in.readUTF());      // Input data
                String id = scanner.next();
                out.writeUTF(id);
                if(id.equals("stop"))
                    break;

                String name = scanner.next();
                out.writeUTF(name);

                int attendance = scanner.nextInt();
                out.writeInt(attendance);

                int assignment = scanner.nextInt();
                out.writeInt(assignment);

                int midterm = scanner.nextInt();
                out.writeInt(midterm);

                int finalterm = scanner.nextInt();
                out.writeInt(finalterm);



                System.out.println("Server says : "+in.readUTF());
                out.flush();

            }

            int table_size = in.readInt();




        }
        catch(IOException e)
        {
            e.printStackTrace();
        }
    }
}
