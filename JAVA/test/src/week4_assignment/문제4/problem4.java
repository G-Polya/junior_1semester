package week4_assignment;

import java.util.Scanner;

public class problem4 
{
	static void spiral_matrix(int size)
	{
		int matrix[][] = new int[size][size];
		
		int count = 0;
		int col, row;
		
		for(col = 0; col < (size/2)+1;col++)
		{
			for(row = col; row < size - col; row++)
				matrix[col][row] = count++;
			
			for(row = col+1;row<size-col;row++)
				matrix[row][size-col-1]= count++;
			
			for(row = size - col -2; row>= col;row--)
				matrix[size-col-1][row] = count++;
			
			for(row = size - col - 2; row>=col+1;row--)
				matrix[row][col] = count++;
				
		}
		
		
		for(int new_col = 0 ; new_col<matrix.length;new_col++)
		{
			for(int new_row = 0; new_row<matrix[0].length;new_row++)
				System.out.print(String.format("%3d", matrix[new_col][new_row]));
			System.out.println();
		}
	}
	
	public static void main(String[] args)
	{
		System.out.print("수를 입력하시오: ");
		Scanner sc = new Scanner(System.in);
		int size = sc.nextInt();
		
		spiral_matrix(size);
		System.out.println();
	}
}
