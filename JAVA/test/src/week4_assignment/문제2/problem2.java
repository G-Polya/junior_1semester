package week4_assignment;

import java.util.Scanner;

public class problem2 
{
	static void zigzag_matrix(int size)
	{
		int matrix[][] = new int[size][size];
		
		for(int col = 0; col<matrix.length;col++)
		{
			for(int row = 0; row<matrix.length;row++)
			{
				if(col % 2==0)
					matrix[col][row] = row + col * size;
				else 
					matrix[col][row] = (size - row - 1) + col * size;
			}
		}
		
		for(int col = 0 ; col<matrix.length;col++)
		{
			for(int row = 0; row<matrix[0].length;row++)
				System.out.print(String.format("%3d", matrix[col][row]));
			System.out.println();
		}
		
	}
	
	public static void main(String[] args)
	{
		System.out.print("수를 입력하시오: ");
		Scanner sc = new Scanner(System.in);
		int size = sc.nextInt();
		
		zigzag_matrix(size);
		System.out.println();
	}
}
