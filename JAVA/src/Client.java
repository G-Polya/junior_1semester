
import java.io.*;
import java.net.Socket;
import java.nio.Buffer;
import java.sql.*;
import java.util.Scanner;


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

            System.out.println("Server says : "+in.readUTF());      // Input user name >>
            String username = scanner.next();
            out.writeUTF(username);


            System.out.println("Server says : "+in.readUTF());      // Input password >>
            String password = scanner.next();
            out.writeUTF(password);

            System.out.println("Server says : "+in.readUTF());      // Input database name >>
            String dbName = scanner.next();
            out.writeUTF(dbName);

            out.flush();

        }
        catch(IOException e)
        {
            e.printStackTrace();
        }
    }
}
