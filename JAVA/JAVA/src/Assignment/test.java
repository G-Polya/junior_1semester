package Assignment;
import java.util.Scanner;
import java.util.StringTokenizer;


public class test
{
    public static void main(String[] args)
    {
        // TODO Auto-generated method stub
        Scanner sc = new Scanner(System.in);
        String input_str = "";
//        StringTokenizing stz2 =new StringTokenizing();

        System.out.println("Input($로 입력 종료) >> ");
        while(true)
        {
            String input = sc.nextLine();
            if(input.contentEquals("$"))
            {
                break;
            }
            else
            {
                input_str = input_str.concat(input+"\n");
            }
        }

        //    stz2.run(input_str);
        StringTokenizer st = new StringTokenizer(input_str, " ={};\t\r\n,");
        System.out.println("Output >> ");
        while(st.hasMoreTokens())
            System.out.println(st.nextToken()) ;
    }
}
