

public class problem2 
{
	static double Newton_Method_CubeRoot(double X, int ntimes)
	{
		if(ntimes == 0)
			return 1.0;
		
		double before = Newton_Method_CubeRoot(X, ntimes-1);
		
		
		return before - (before*before*before - X)/(3*before*before);
	}
	
	public static void main(String[] args)
	{
		for(int i =0 ;i < 40;i++)
		{
			System.out.println(i+" : "+Newton_Method_CubeRoot(Math.pow(2,27),i));
			
			System.out.println();
		}
	}

}
