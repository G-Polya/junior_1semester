import java.io.*;
import java.net.*;

public class MyClient
{
	public static void main(String[] args)
	{
		try
		{
			Socket s=new Socket("localhost",6666);	// make client
			DataOutputStream dout=new DataOutputStream(s.getOutputStream()); // make output stream
			dout.writeUTF("Hello Server");	// write
			dout.flush();
			dout.close();
			s.close();
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}
	}
}