package Assignment;
import java.util.Scanner;
import java.util.StringTokenizer;

public class test 
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		String input="";
		
		while(sc.hasNextLine()) 
		{
			input= sc.nextLine();
			
			StringTokenizer st = new StringTokenizer(input, " ={};\t\r\n,", true);
			//System.out.println("Input:"+ input);
			while(st.hasMoreTokens())
				System.out.println(st.nextToken());
		
			
		}

	
	}

}
