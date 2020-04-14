import java.util.Scanner;

public class week4_ZigzagSpiralMatrix 
{
	//����1
	static void make_matrix(int size)
	{
		int matrix[][] = new int[size][size];		//2���� �迭
	
		for(int col = 0; col<matrix.length;col++)	//(i,j)���. i�� j��
		{
			for(int row = 0;row<matrix[0].length;row++)
			{
				matrix[col][row] = row + col * size;	// 2���� �迭�� �ʱ�ȭ
			}
		}
		
		for(int col = 0 ; col<matrix.length;col++)
		{
			for(int row = 0; row<matrix[0].length;row++)
				System.out.print(String.format("%3d", matrix[col][row]));	//2�����迭 ���
			System.out.println();
		}
		
	}
		
	//����2
	static void zigzag_matrix(int size)
	{
		int matrix[][] = new int[size][size];		// 2���� �迭 ����
		
		for(int col = 0; col<matrix.length;col++)
		{
			for(int row = 0; row<matrix.length;row++)
			{
				if(col % 2==0)								// 0, 2, 4,...��° column�� ���ؼ�...
					matrix[col][row] = row + col * size;	// 1���� 2�����迭ó�� �ʱ�ȭ 
				else 										// 1, 3, 5,...��° column�� ���ؼ� 
					matrix[col][row] = (size - row - 1) + col * size;	// �Ųٷ� �ʱ�ȭ. ū������ �ʱ�ȭ
			}
		}
		
		for(int col = 0 ; col<matrix.length;col++)
		{
			for(int row = 0; row<matrix[0].length;row++)
				System.out.print(String.format("%3d", matrix[col][row]));		// ���
			System.out.println();
		}
		
	}
	//����3
	static void zigzag_NoArray(int size)
	{
		int element = 0;			// �迭�� ���� ������ �ϴ� ����. ���� ���Ҵ� �ƴϴ�
		
		for(int col = 0 ; col<size;col++)
		{
			int temp = element;		// Ȧ����° column���� element ��� ���� ���� temp
			
			for(int row = 0; row < size;row++)
			{
				if(col % 2 ==0)		// ¦����° column���� element�� �̵��Ҷ����� �����ϸ� ��
					System.out.print(String.format("%3d",element));
				else
				{	// Ȧ����° column���� �̵��Ҷ����� temp�� ���ҽ�Ŵ. �׷��� �����ʺ��� ū���� ��µȴ�
					System.out.print(String.format("%3d",(size-1)+temp));	
					temp --;
				}
				element++;		// �����϶����� 1�� ������Ŵ. 
			}
			System.out.println();
		}
	}
	
	// ����4
	static void spiral_matrix(int size)
	{
		int matrix[][] = new int[size][size];			// 2���� �迭 ����
		
		int count = 0;		// �̵��Ҵ븶�� �ϳ��� �����Ǿ� �迭�� ���Ұ� ��
		int col, row;
		
		for(col = 0; col < (size/2)+1;col++)
		{
			for(row = col; row < size - col; row++)
				matrix[col][row] = count++;				// ���ʿ��� ���������� ���� ����
			
			for(row = col+1;row<size-col;row++)
				matrix[row][size-col-1]= count++;		// ���ʿ��� �Ʒ������� ���� ����
			
			for(row = size - col -2; row>= col;row--)	// �����ʿ��� �������� ���� ����
				matrix[size-col-1][row] = count++;
			
			for(row = size - col - 2; row>=col+1;row--)	// �Ʒ��ʿ��� �������� ���� ����
				matrix[row][col] = count++;
				
		}
		
		
		for(int new_col = 0 ; new_col<matrix.length;new_col++)
		{
			for(int new_row = 0; new_row<matrix[0].length;new_row++)
				System.out.print(String.format("%3d", matrix[new_col][new_row]));	// �迭 ���
			System.out.println();
		}
	}
		
	// �־��� ��ġ���� �����ڸ����� �������ִ� �ּҰŸ��� ���ϴ� �Լ�
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
		
		// �ᱹ 2�����迭�� ū ���ȿ� ���� ���� ����մ� ����̴�
		static void spiral_NoArray(int size)
		{
			int element;
			
			// ��Ģ1
			// row >= col�϶�, (row,col)��ġ�� ���Ҵ� (row+col)�̰�
			// row < col�϶�, ���Ҵ� (size-1)*4-(row+col)�̴�. �̋� size�� ����� ũ���̴�.
			// ���� �ٱ��� ���ȿ����� �̰��� �� �������� �ι��� �����ʹ� �������� �ʴ´�. 
			for(int col = 0; col<size;col++)
			{
				for(int row =0 ;row<size;row++)
				{
					// position�� (row,col)�� ��Ұ� �����ڸ����� �������ִ� ������ ��Ÿ����
					// position�� �ʿ��� ������ ����(����20)���ʹ� ��Ģ1�� ���� �ʱ� ����			

					int position = min(row,col,size-1-col, size-1-row);
					if(row>=col)
						// 2 * position�� ���ָ� ��Ģ1�� ���յ�
						element = row + col - 2*position;
					else
						// 2 * position�� ���ָ� ��Ģ1�� ���յ�
						element = (size-1-2*position) * 4 - (col+row-2*position);
					
					// �� ������ ������ ������ 0���� �����ϰ� ��. ù��° ������ 0~19, �ι�° ������ 0~11...
					// ���� Ư������ ������� ���ӵ� ���ڵ��� ���������� ������
					// �� Ư������ �� 4*(position * size - position^2)
					element += 4 * (position * size-(position*position));
					System.out.print(String.format("%3d",element));
				}
				System.out.println();
			}
		}
		
	public static void main(String[] args)
	{
		System.out.print("���� �Է��Ͻÿ�: ");
		Scanner sc = new Scanner(System.in);
		int size = sc.nextInt();
		
		make_matrix(size);
		System.out.println();
		zigzag_matrix(size);
		System.out.println();
		zigzag_NoArray(size);
		System.out.println();
		spiral_matrix(size);
		System.out.println();
		spiral_NoArray(size);
	}
	
}
