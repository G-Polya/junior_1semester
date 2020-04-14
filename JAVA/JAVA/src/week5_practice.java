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
	
	// 스왑
	public static void swap(int[] array, int i1, int i2)
	{
		int temp = array[i1];
		array[i1] = array[i2];
		array[i2] = temp;
	}
	
	// bubble sort
	public static void bubbleSort(int arr[], int size)
	{
		if(size == 1)
			return;
		
		for(int i = 0; i< size-1;i++)	// 0부터 (arr.length-1)까지에 반복
			if(arr[i] > arr[i+1])		// 앞의 원소가 뒤의 원소보다 작으면
				swap(arr, i, i+1);		// 서로 스왑한다.
		bubbleSort(arr,size-1);			// 재귀적으로
	}
	

	// array 출력
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


public class week5_practice
{
	public static void main(String[] args)
	{
		int[] array1 = {1,5,7,9};
		int[] array2 = {3,6,-1,100,77};
		int[] array3 = ArrayUtil.concat(array1, array2);
		System.out.print("Original Array: ");
		ArrayUtil.print(array3);
		System.out.print("Sorted Array: ");
		ArrayUtil.bubbleSort(array3,array3.length);
		ArrayUtil.print(array3);
	}
}
