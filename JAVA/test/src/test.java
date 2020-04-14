
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
	
	public static void swap(int[] array, int i1, int i2)
	{
		int temp = array[i1];
		array[i1] = array[i2];
		array[i2] = temp;
	}
	
	
	public static int partition(int[] a, int low, int high)
	{
		int pivotIndex = low + (high - low)/2;		// ��Ƽ���� �߰����� �����ϵ��� pivot ����
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
		
		// low�� high�� �ʱⰪ�� ���ÿ� Ǫ��
		stk[++top] = low;
		stk[++top] = high;
		
		while(top>=0)
		{
			high = stk[top--];
			low = stk[top--];
			
			int pivot = partition(array,low,high);		// ��Ƽ��
			
			if(pivot - 1> low)							// �ε��� ��: �Ǻ������� ���ҿ� ���Ͽ�
			{
				stk[++top] = low;
				stk[++top] = pivot;
			}
			
			if(pivot + 1 <high)							// �ε��� ��: �Ǻ� �������� ���ҿ� ���Ͽ�
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
