package week4_assignment;

import java.util.Scanner;

public class problem3 
{
	//문제3
	static void zigzag_NoArray(int size)
	{
		int element = 0;
		for(int col =0 ; col<size;col++)
		{
			int temp = element;
			
			for(int row = 0; row < size;row++)
			{
				if(col % 2==0)
					System.out.print(String.format("%3d",element));
				else
				{
					System.out.print(String.format("%3d",(size-1)+temp));
					temp --;
				}
				element++;
			}
			System.out.println();
		}
	}
	
	public static void main(String[] args)
	{
		System.out.print("수를 입력하시오: ");
		Scanner sc = new Scanner(System.in);
		int size = sc.nextInt();
		
		zigzag_NoArray(size);
		System.out.println();
	}
}
