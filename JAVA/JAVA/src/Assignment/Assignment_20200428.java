package Assignment;

import java.util.StringTokenizer;
import java.util.Scanner;
import java.io.*;

class StringTokenizing
{
	public static void run(String str)
	{
		StringTokenizer st = new StringTokenizer(str, " ={};\t\r\n,", true);
		int n = st.countTokens();
		
		int i = 0;
		String[] tokens = new String[n];
		while(st.hasMoreTokens())
		{
			tokens[i++] = st.nextToken();
		}
	}
	
}

public class Assignment_20200428 
{
	
	public static void main(String[] args)
	{
		Scanner scanner = new Scanner(System.in);
		String str = "";
		
		while(true)
		{
			String input = scanner.nextLine();
			if(input.contentEquals(("@"))
					break;
			else
			{
				str = str.concat(input+"\n");
			}
		}
	}
}
