
import java.util.Scanner;

public class chapter6_problem8
{
	public static void main(String[] args)
	{
		Scanner scanner = new Scanner(System.in);
		System.out.println("���ڿ��� �Է��ϼ���. ��ĭ�� �־ �ǰ� ���� �ѱ� ��� �˴ϴ�");
		String input_str = scanner.nextLine();
		
		int len = input_str.length();
		
		for(int i = 0; i<len;i++)
		{
			String first = input_str.substring(0,1);
			String last = input_str.substring(1);
			input_str = last + first;
			
			System.out.println(input_str);
		}
		
	}

}
