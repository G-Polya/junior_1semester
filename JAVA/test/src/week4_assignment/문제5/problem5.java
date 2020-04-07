package week4_assignment;

import java.util.Scanner;

public class problem5 
{
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
		
		spiral_NoArray(size);
		System.out.println();
	}

}
