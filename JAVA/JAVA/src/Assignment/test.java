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
		System.out.println(srcString()+"�� " +destString()+"(��)�� �ٲߴϴ�");
		System.out.print(srcString()+"�� �Է��ϼ���>> ");
		double value = scan.nextDouble();
		double result = convert(value);
		System.out.println("��ȯ���: "+result+destString()+"�Դϴ�");
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
		return "��";
	}
	
	@Override 
	protected String destString()
	{
		return "�޷�";
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
