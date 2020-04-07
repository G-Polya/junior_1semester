package week4_assignment;

import java.util.Scanner;

public class problem1
{
	//문제1
	static void make_matrix(int size)
	{
		int matrix[][] = new int[size][size];
	
		for(int col = 0; col<matrix.length;col++)
		{
			for(int row = 0;row<matrix[0].length;row++)
			{
				matrix[col][row] = row + col * size;
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
		
		make_matrix(size);
		System.out.println();
	}
}
