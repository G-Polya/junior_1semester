package Assignment;

import java.io.*;
import java.util.*;

public class 교재8장_실습
{
	public static Scanner readJAVA(String filename)
	{
		Scanner inputTxt = null;
		try
		{
			inputTxt = new Scanner(new FileReader(filename)).useDelimiter("\n");	// 개행문자로 구분될것
			
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}
		return inputTxt;
	}
	
	public static void make_output(String[] tokens, String filepath)
	{
		try
		{
			BufferedWriter fw = new BufferedWriter(new FileWriter(filepath,true));		// 정보가 저장될 BufferedWriter 객체
			
			for(int i = 0; i < tokens.length;i++)	// 토큰의 수만큼
			{
				fw.write(tokens[i]);	// fw에 입력
				fw.newLine();
			}
			fw.flush();
			fw.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
	
	
	public static void main(String args[])
	{
		
		
		
		String java_file = "C:\\Users\\wlska\\Documents\\junior_1semester\\JAVA\\src\\Assignment\\BitStringout.java";
		Scanner sc = readJAVA(java_file);		// // inputFile.csv 읽어오기
        
		String input_str = "";					// input_str 초기화
       
        while(sc.hasNext())
        {
        	String input = sc.next();
        	input_str = input_str.concat(input+"\n");
        }
        
        StringTokenizer st = new StringTokenizer(input_str, " ={};\t\r\n,");	// input_str을 StringTokenizer로 토큰화
        int index = 0, temp = 0;
        
        String[] tokens = new String[st.countTokens()];// 토큰들이 들어가는 배열 tokens
        
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
        
        make_output(tokens,"C:\\Users\\wlska\\Documents\\junior_1semester\\JAVA\\src\\Assignment\\output.txt");	// output파일 만들기.
	}
	
}
