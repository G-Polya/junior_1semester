package Assignment;

import java.util.StringTokenizer;
import java.util.Scanner;

public class 교재6장실습 
{
	
	public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);			// Scanner 객체 생성
        String input_str = "";		// input_str 초기화

        System.out.println("Input($로 입력 종료) >> ");
        while(true)
        {
            String input = sc.nextLine();	// 문자열 한줄씩 입력
            if(input.contentEquals("$"))	// while문 종료를 위한 flag $	
                break;
            else
                input_str = input_str.concat(input+"\n");	//완성된 문자열
            
        }
        
        StringTokenizer st = new StringTokenizer(input_str, " ={};\t\r\n,");	// input_str을 StringTokenizer로 토큰화
        int index = 0, temp = 0;
        
        String[] tokens = new String[st.countTokens()]; // 토큰들이 들어가는 배열 tokens
        
        System.out.println("Output >> ");
        while(st.hasMoreTokens())
        	tokens[index++] = st.nextToken();		// 배열 초기화.. 이제 tokens에는 input_str을 토큰화한 값들이 들어감
        
        for(int i = 0; i< tokens.length;i++)
        {
        	try
        	{
        		temp = Integer.parseInt(tokens[i]);	// 토큰 중에서 정수("1", "6")는 변환이 되지만 문자열("Example", "Example2")는 변환이 안돼서 NumberFormatException 발생
        	}
        	catch(NumberFormatException e)			
        	{
        		System.out.println(tokens[i]);		// 숫자 리터럴을 제외한 값들만 출력
        	}
        }
    }
}
