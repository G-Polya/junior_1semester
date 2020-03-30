
public class week3 
{
	static double Newton_Method_SQRT(double X, int ntimes)
	{
		if(ntimes == 0)
			return 1.0;
	
		double before = Newton_Method_SQRT(X, ntimes-1);
		//return Newton_Method_SQRT(X, ntimes-1) - (Newton_Method_SQRT(X, ntimes-1)*Newton_Method_SQRT(X, ntimes-1) - X)/(2*Newton_Method_SQRT(X, ntimes-1));
		return before - (before*before - X) / (2*before);
	}
	
	static double Newton_Method_CubeRoot(double X, int ntimes)
	{
		if(ntimes == 0)
			return 1.0;
		
		double before = Newton_Method_CubeRoot(X, ntimes-1);
		
		
		return before - (before*before*before - X)/(3*before*before);
	}
	
	public static void main(String[] args)
	{
		for(int i =0 ;i < 20;i++)
		{
			System.out.println(i+" : "+Newton_Method_SQRT(1073741824,i));
			System.out.println(i+" : "+Newton_Method_CubeRoot(1000,i));
			System.out.println();
		}
	}

}
