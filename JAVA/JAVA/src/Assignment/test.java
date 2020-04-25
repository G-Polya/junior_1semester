package Assignment;
import java.util.Scanner;

abstract class Converter
{
	abstract protected double convert(double src);
	abstract protected String srcString();
	abstract protected String destString();
	protected double rate;
	
	public void run()
	{
		Scanner scan = new Scanner(System.in);
		System.out.println(srcString()+"을 " +destString()+"(으)로 바꿉니다");
		System.out.print(srcString()+"을 입력하세요>> ");
		double value = scan.nextDouble();
		double result = convert(value);
		System.out.println("변환결과: "+result+destString()+"입니다");
	}
}

class Won2Dollar extends Converter
{
	public Won2Dollar(int i)
	{
		this.rate = i;
	}
	
	@Override
	protected double convert(double src)
	{
		return (src/this.rate);
	}

	@Override
	protected String srcString()
	{
		return "원";
	}
	
	@Override 
	protected String destString()
	{
		return "달러";
	}
	
}

class Km2Mile extends Converter
{
	public Km2Mile(double input)
	{
		this.rate = input;
	}
	
	@Override
	protected double convert(double src)
	{
		return (src/this.rate);
	}
	
	@Override
	protected String srcString()
	{
		return "Km";
	}
	
	@Override 
	protected String destString()
	{
		return "mile";
	}
	
}

public class test 
{
	public static void main(String[] args)
	{
		Km2Mile toMile = new Km2Mile(1.6);
		toMile.run();
	}

}
