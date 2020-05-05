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
			// ���� �б� �غ�
			String input = "C:\\Users\\wlska\\Documents\\junior_1semester\\JAVA\\JAVA\\src\\Assignment\\input.txt";
			Scanner inputTxt = new Scanner(new FileReader(input)); // ������ �о���� Scanner ��ü
			
			// ���� ���� �غ�
			String output = "C:\\Users\\wlska\\Documents\\junior_1semester\\JAVA\\JAVA\\src\\Assignment\\output.txt";
			FileWriter outputTxt = new FileWriter(output); // writer�� ���� ��ü
			
			for(int i = 0 ;i < 5;i++)
			{
				// input.txt���� �о���� �� ��
				double	a = inputTxt.nextDouble();
				double	b = inputTxt.nextDouble();
						
					
				String result = a + " + " + b + " = " + (a+b);
				System.out.println(result);

				// �� ���� ��(���)�� output.txt���Ͽ� ����
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
