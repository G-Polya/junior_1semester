package Assignment;
import java.util.Scanner;

public class week4_ZigzagSpiralMatrix
{
	//문제1
	static void make_matrix(int size)
	{
		int matrix[][] = new int[size][size];		//2차원 배열

		for(int col = 0; col<matrix.length;col++)	//(i,j)행렬. i행 j열
		{
			for(int row = 0;row<matrix[0].length;row++)
			{
				matrix[col][row] = row + col * size;	// 2차원 배열을 초기화
			}
		}

		for(int col = 0 ; col<matrix.length;col++)
		{
			for(int row = 0; row<matrix[0].length;row++)
				System.out.print(String.format("%3d", matrix[col][row]));	//2차원배열 출력
			System.out.println();
		}

	}

	//문제2
	static void zigzag_matrix(int size)
	{
		int matrix[][] = new int[size][size];		// 2차원 배열 선언

		for(int col = 0; col<matrix.length;col++)
		{
			for(int row = 0; row<matrix.length;row++)
			{
				if(col % 2==0)								// 0, 2, 4,...번째 column에 대해선...
					matrix[col][row] = row + col * size;	// 1번의 2차원배열처럼 초기화
				else 										// 1, 3, 5,...번째 column에 대해선
					matrix[col][row] = (size - row - 1) + col * size;	// 거꾸로 초기화. 큰수부터 초기화
			}
		}

		for(int col = 0 ; col<matrix.length;col++)
		{
			for(int row = 0; row<matrix[0].length;row++)
				System.out.print(String.format("%3d", matrix[col][row]));		// 출력
			System.out.println();
		}

	}
	//문제3
	static void zigzag_NoArray(int size)
	{
		int element = 0;			// 배열의 원소 역할을 하는 변수. 실제 원소는 아니다

		for(int col = 0 ; col<size;col++)
		{
			int temp = element;		// 홀수번째 column에서 element 대신 쓰기 위한 temp

			for(int row = 0; row < size;row++)
			{
				if(col % 2 ==0)		// 짝수번째 column에선 element가 이동할때마다 증가하면 됨
					System.out.print(String.format("%3d",element));
				else
				{	// 홀수번째 column에선 이동할때마다 temp를 감소시킴. 그러면 오른쪽부터 큰수가 출력된다
					System.out.print(String.format("%3d",(size-1)+temp));
					temp --;
				}
				element++;		// 움직일때마다 1씩 증가시킴.
			}
			System.out.println();
		}
	}

	// 문제4
	static void spiral_matrix(int size)
	{
		int matrix[][] = new int[size][size];			// 2차원 배열 선언

		int count = 0;		// 이동할대마다 하나씩 증가되어 배열의 원소가 됨
		int col, row;

		for(col = 0; col < (size/2)+1;col++)
		{
			for(row = col; row < size - col; row++)
				matrix[col][row] = count++;				// 왼쪽에서 오른쪽으로 값을 넣음

			for(row = col+1;row<size-col;row++)
				matrix[row][size-col-1]= count++;		// 위쪽에서 아래쪽으로 값을 넣음

			for(row = size - col -2; row>= col;row--)	// 오른쪽에서 왼쪽으로 값을 넣음
				matrix[size-col-1][row] = count++;

			for(row = size - col - 2; row>=col+1;row--)	// 아래쪽에서 위쪽으로 값을 넣음
				matrix[row][col] = count++;

		}


		for(int new_col = 0 ; new_col<matrix.length;new_col++)
		{
			for(int new_row = 0; new_row<matrix[0].length;new_row++)
				System.out.print(String.format("%3d", matrix[new_col][new_row]));	// 배열 출력
			System.out.println();
		}
	}

	// 주어진 위치에서 가장자리까지 떨어져있는 최소거리를 구하는 함수
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

	// 결국 2차원배열은 큰 ㅁ안에 작은 ㅁ가 들어잇는 모습이다
	static void spiral_NoArray(int size)
	{
		int element;

		// 규칙1
		// row >= col일때, (row,col)위치의 원소는 (row+col)이고
		// row < col일때, 원소는 (size-1)*4-(row+col)이다. 이 size는 행렬의 크기이다.
		// 제일 바깥의 ㅁ안에서는 이것이 잘 들어맞으나 두번 ㅁ부터는 성립하지 않는다.
		for(int col = 0; col<size;col++)
		{
			for(int row =0 ;row<size;row++)
			{
				// position은 (row,col)의 요소가 가장자리에서 떨어져있는 정도를 나타낸다
				// position이 필요한 이유는 안쪽(숫자20)부터는 규칙1이 맞지 않기 문

				int position = min(row,col,size-1-col, size-1-row);
				if(row>=col)
					// 2 * position을 빼주면 규칙1에 부합됨
					element = row + col - 2*position;
				else
					// 2 * position을 빼주면 규칙1에 부합됨
					element = (size-1-2*position) * 4 - (col+row-2*position);

				// 위 과정을 끝내면 ㅁ마다 0부터 시작하게 됨. 첫번째 ㅁ에는 0~19, 두번째 ㅁ에는 0~11...
				// 따라서 특정값을 더해줘야 연속된 숫자들이 나선형으로 나열됨
				// 그 특정값이 곧 4*(position * size - position^2)
				element += 4 * (position * size-(position*position));
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
		zigzag_matrix(size);
		System.out.println();
		zigzag_NoArray(size);
		System.out.println();
		spiral_matrix(size);
		System.out.println();
		spiral_NoArray(size);
	}

}
