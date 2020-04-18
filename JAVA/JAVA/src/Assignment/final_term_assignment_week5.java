package Assignment;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class final_term_assignment_week5
{
	public static void main(String[] args) throws FileNotFoundException
	{
		try
		{
			// 파일 읽기 준비
			String input = "C:\\Users\\wlska\\Documents\\junior_1semester\\JAVA\\JAVA\\src\\Assignment\\input.txt";
			Scanner inputTxt = new Scanner(new FileReader(input)); // 파일을 읽어들인 Scanner 객체
			
			// 파일 쓰기 준비
			String output = "C:\\Users\\wlska\\Documents\\junior_1semester\\JAVA\\JAVA\\src\\Assignment\\output.txt";
			FileWriter outputTxt = new FileWriter(output); // writer할 파일 객체
			
			for(int i = 0 ;i < 5;i++)
			{
				// input.txt에서 읽어들인 두 수
				double	a = inputTxt.nextDouble();
				double	b = inputTxt.nextDouble();
						
					
				String result = a + " + " + b + " = " + (a+b);
				System.out.println(result);

				// 두 수의 합(결과)를 output.txt파일에 쓰기
				outputTxt.write(result+"\n");
			}
			outputTxt.close();
		}
		catch(IOException e)
		{
			System.out.println(e.getMessage());
		}
	}
}
