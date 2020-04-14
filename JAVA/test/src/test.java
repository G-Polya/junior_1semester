
class ArrayUtil
{
	
	
	public static int[] concat(int[] a, int[] b)
	{
		// 배열 a,b의 원소를 저장할 임시 배열 temp. 
		// a,b의 모든원소가 들어가야하므로 temp.length는 a.length+b.length이다. 
		int temp[] = new int[a.length+b.length];
		
		// 배열 a의 원소 저장.
		for(int i = 0; i < a.length;i++)
			temp[i] = a[i];
		
		
		// a의 원소가 저장된 후부터 배열 b의 원소 저장
		for (int i = a.length; i<a.length+b.length;i++)
			temp[i] = b[i-a.length];
		
		return temp;
		
	}
	
	public static void swap(int[] array, int i1, int i2)
	{
		int temp = array[i1];
		array[i1] = array[i2];
		array[i2] = temp;
	}
	
	
	public static int partition(int[] a, int low, int high)
	{
		int pivotIndex = low + (high - low)/2;		// 파티션이 중간부터 시작하도록 pivot 설정
		int pivotValue = a[pivotIndex];
		
		int i = low, j = high;
		
		while( i<= j)
		{
			while(a[i] < pivotValue)	
				i++;
			while(a[j] > pivotValue)
				j--;
			
			if (i <= j)
			{
				swap(a, a[i], a[j]);
				i++;
				j--;
			}
			
		}
		
		return i;
	}
	
	
	
	public static void ascendingArray(int[] array)
	{
		int low = 0;
		int high = array.length - 1;
		
		int stk[] = new int[high-low+1];
		int top = -1;
		
		// low와 high의 초기값을 스택에 푸시
		stk[++top] = low;
		stk[++top] = high;
		
		while(top>=0)
		{
			high = stk[top--];
			low = stk[top--];
			
			int pivot = partition(array,low,high);		// 파티션
			
			if(pivot - 1> low)							// 인덱스 비교: 피봇왼쪽의 원소에 대하여
			{
				stk[++top] = low;
				stk[++top] = pivot;
			}
			
			if(pivot + 1 <high)							// 인덱스 비교: 피봇 오른쪽의 원소에 대하여
			{
				stk[++top] = pivot + 1;
				stk[++top] = high;
			}
			
		}
	}
	
	
	public static void print(int[] a)
	{
		System.out.print("[ ");
		for(int i = 0; i < a.length;i++)
		{
			System.out.print(a[i]+" ");
		}
		System.out.println("]");
			
	}
}
public class test 
{
	public static void main(String[] args)
	{
		int[] array1 = {1,5,7,9};
		int[] array2 = {3,6,-1,100,77};
		int[] array3 = ArrayUtil.concat(array1, array2);
		ArrayUtil.print(array3);
		ArrayUtil.ascendingArray(array3);
		ArrayUtil.print(array3);
	}
}
