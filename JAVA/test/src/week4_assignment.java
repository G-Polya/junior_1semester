import java.util.Scanner;


public class week4_assignment
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
	
	//문제2
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
	
	// 문제4
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
	
	static int min(int x, int y, int z ,int w)
	{
		int min = x;
		int arr[] = {x,y,z,w};
		for(int i = 0; i< arr.length;i++)
		{
			if(arr[i]<min)
				min=arr[i];
		}
		
		return min;
 	}
	
	
	static void spiral_NoArray(int size)
	{
		int element;
		
		for(int col = 0; col<size;col++)
		{
			for(int row =0 ;row<size;row++)
			{

				int position = min(row,col,size-1-col, size-1-row);
				if(row>=col)
					element = row + col - 2*position;
				else
					element = (size-1-2*position) * 4 - (col+row-2*position);
				
				element += 4* (position * size-(position*position));
				System.out.print(String.format("%3d",element));
			}
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
		zigzag_matrix(6);
		System.out.println();
		zigzag_NoArray(size);
		System.out.println();
		spiral_matrix(size);
		System.out.println();
		spiral_NoArray(size);
	}
}
