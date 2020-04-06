class StaticMethod
{
	public int m;
	static int add(int b)
	{
		return m + b;
	}
}


public class java0331
{
	public static void main(String[] args)
	{
		StaticMethod a = new StaticMethod();
		a.m = 4;
		System.out.println(a.add(5));
	}

}
