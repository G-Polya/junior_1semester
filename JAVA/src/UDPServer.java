import java.net.*;
import java.io.*;

public class UDPServer
{
   public UDPServer(int port)
   {
       try
       {
           DatagramSocket ds = new DatagramSocket(port);    // 데이터그램을 송수신하기위한 소켓객체
           while(true)
           {
               byte buffer[] = new byte[512];
               DatagramPacket dp = new DatagramPacket(buffer,buffer.length);    // 버퍼 크기만큼의 데이터그램 패킷객체 생성
               System.out.println("ready");
               ds.receive(dp);  // 데이터그램을 받아서 패킷객체 dp에 저장
               String str = new String(dp.getData());   // 받아온 데이터그램의 데이터를 String타입으로
               System.out.println("received data : "+str);  // 수신된 데이터 출력

               InetAddress ia = dp.getAddress();    // dp의 ip Address를 저장하는 객체 생성
               port =dp.getPort(); // dp의 port
               System.out.println("client ip : "+ia+" , client port : "+port);
               dp = new DatagramPacket(dp.getData(),dp.getData().length, ia, port); //서버의 ip주소와 port가 포함된 dp 객체 재정의
               ds.send(dp); // 전송
           }
       }
       catch(IOException ioe)
       {
           ioe.printStackTrace();
       }
   }

   public static void main(String[] args)
   {
       new UDPServer(3000);
   }
}
