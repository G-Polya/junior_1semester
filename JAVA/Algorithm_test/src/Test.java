
public class Test
{
	public int sum(int m, int n)
	{
		return m + n;
	}
	
	public static int add(int a, int b)
	{
		return a + b;
	}
	public static void main(String[] args)
	{
		Test test = new Test();
		
		int result1 = test.sum(3, 4);
		int result2 = add(5,6);
		int result3 = test.add(7, 8);
		
		System.out.println(result1);
		System.out.println(result2);
		System.out.println(result3);
	}

}
