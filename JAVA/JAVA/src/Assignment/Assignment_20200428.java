package Assignment;

import java.util.StringTokenizer;
import java.util.Scanner;
import java.io.*;

public class Assignment_20200428 
{
	public static void main(String[] args)
	{
		Scanner scanner = new Scanner(System.in);
		//"{},; =	\n\r"
		StringTokenizer st = new StringTokenizer(scanner.nextLine(),"\\n")  ;
		System.out.println();
		
	
		while(st.hasMoreTokens())
			System.out.println(st.nextToken());
	}
}
