import java.io.*;
import java.net.*;

public class MyServer
{
	public static void main(String[] args)
	{
		try
		{
			ServerSocket ss=new ServerSocket(6666);	// Create Server
			Socket s=ss.accept();//establishes connection
			DataInputStream dis=new DataInputStream(s.getInputStream()); // make Input stream received from Client(s)
			String  str=(String)dis.readUTF();	// Convert data to String type
			System.out.println("message= "+str);	// print
			ss.close();
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}
	}
}