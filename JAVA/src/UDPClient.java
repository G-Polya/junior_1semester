import javax.print.DocFlavor;
import java.net.*;
import java.io.*;


public class UDPClient
{
    private String str;
    private BufferedReader file;
    private static int SERVERPORT = 3000;

    public UDPClient(String ip,int port)
    {
        try
        {
            InetAddress ia = InetAddress.getByName(ip); // instacne to present IP address
            DatagramSocket ds = new DatagramSocket(port); // DatagramSocket객체가 데이터 그램을 송수신할 수 있다..instace to receive datagram
            System.out.print("message : ");
            file = new BufferedReader((new InputStreamReader((System.in))));    // 콘솔입력을 읽어오기 위한 객체
            str = file.readLine();  // 콘솔입력
            byte buffer[] = str.getBytes();
            DatagramPacket dp = new DatagramPacket(buffer,buffer.length,ia,SERVERPORT);// 데이터를 송신하기 위한 데이터그램패킷 객체. 클라이언트의 ip주소와 port가 포함됨
            ds.send(dp);    // 데이터그램 송신

            buffer = new byte[512];
            dp = new DatagramPacket(buffer,buffer.length);  // 서버로부터 수신하기위 한 패킷객체
            ds.receive(dp); // 패킷을 받아서 패킷객체 dp에 저장
            System.out.println("server ip : "+dp.getAddress()+", server port : "+ dp.getPort());    // 수신된 패킷의 server ip, server port출력
            System.out.println("received data : "+new String(dp.getData()).trim());
        }
        catch(IOException ioe)
        {
            ioe.printStackTrace();
        }
    }

    public static void main(String[] args)
    {
        new UDPClient("localhost",2000);
    }
}
