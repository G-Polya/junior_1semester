class ArrayUtil
{
	
	
	public static int[] concat(int[] a, int[] b)
	{
		// �迭 a,b�� ���Ҹ� ������ �ӽ� �迭 temp. 
		// a,b�� �����Ұ� �����ϹǷ� temp.length�� a.length+b.length�̴�. 
		int temp[] = new int[a.length+b.length];
		
		// �迭 a�� ���� ����.
		for(int i = 0; i < a.length;i++)
			temp[i] = a[i];
		
		
		// a�� ���Ұ� ����� �ĺ��� �迭 b�� ���� ����
		for (int i = a.length; i<a.length+b.length;i++)
			temp[i] = b[i-a.length];
		
		return temp;
		
	}
	
	// ����
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
		
		for(int i = 0; i< size-1;i++)	// 0���� (arr.length-1)������ �ݺ�
			if(arr[i] > arr[i+1])		// ���� ���Ұ� ���� ���Һ��� ������
				swap(arr, i, i+1);		// ���� �����Ѵ�.
		bubbleSort(arr,size-1);			// ���������
	}
	

	// array ���
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
