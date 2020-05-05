package Assignment;
import java.util.Scanner;


// �߻�Ŭ���� Calc
// a,b,setvalue()�� �Ļ�Ŭ���� ��ο��� ���� ����� ����
// calculate()�� �Ļ�Ŭ�������� �ٸ� ������ �����ϹǷ� �߻�޼ҵ�� ����
abstract class Calc
{
	protected int a;
	protected int b;
	
	protected void setValue(int a,int b)
	{
		this.a = a;
		this.b = b;
	}
	
	abstract protected int calculate();
}

// 4���� �Ļ�Ŭ���� Add, Sub, Mul, Div
// Calc�� ��ӹ޴´�
// �߻�޼ҵ� calculate()�� �������̵��Ͽ� ��üȭ
class Add extends Calc
{

	protected int calculate()
	{
		return a + b;
	}
}

class Sub extends Calc
{

	protected int calculate()
	{
		return a - b;
	}
}

class Mul extends Calc
{

	protected int calculate()
	{
		return a * b;
	}
}

class Div extends Calc
{

	protected int calculate()
	{
		return a / b;
	}
}



public class week6_practice
{
	public static void main(String[] args)
	{
		int operand1, operand2;		// �Է¹��� �ǿ�����
		char operator;				// �Է¹��� ������
		Scanner scan = new Scanner(System.in);
		
		
		// ������, �ǿ����� �Է�
		System.out.print("�� ������ �����ڸ� �Է��Ͻÿ� >> ");
		operand1 = scan.nextInt();
		operand2 = scan.nextInt();
		operator = scan.next().charAt(0);
		Calc operation;
		
		
		// �Էµ� �����ڿ� ���� ���δٸ� case
		switch(operator)
		{
			case '+':
				operation = new Add();	// case���� ��ü�� �ٸ��� ������ ������ ����
				operation.setValue(operand1, operand2);
				System.out.println(operation.calculate());
				break;
				
			case '-':
				operation = new Sub();
				operation.setValue(operand1, operand2);
				System.out.println(operation.calculate());
				break;
				
			case '*':
				operation = new Mul();
				operation.setValue(operand1, operand2);
				System.out.println(operation.calculate());
				break;
			
			case '/':
				operation = new Div();
				operation.setValue(operand1, operand2);
				System.out.println(operation.calculate());
				break;
		}
	}
}
