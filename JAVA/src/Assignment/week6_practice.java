package Assignment;
import java.util.Scanner;


// 추상클래스 Calc
// a,b,setvalue()는 파생클래스 모두에서 같은 기능을 수행
// calculate()는 파생클래스마다 다른 연산을 수행하므로 추상메소드로 선언
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

// 4개의 파생클래스 Add, Sub, Mul, Div
// Calc를 상속받는다
// 추상메소드 calculate()를 오버라이딩하여 구체화
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
		int operand1, operand2;		// 입력받을 피연산자
		char operator;				// 입력받을 연산자
		Scanner scan = new Scanner(System.in);


		// 연산자, 피연산자 입력
		System.out.print("두 정수와 연산자를 입력하시오 >> ");
		operand1 = scan.nextInt();
		operand2 = scan.nextInt();
		operator = scan.next().charAt(0);
		Calc operation;


		// 입력된 연산자에 따라 서로다른 case
		switch(operator)
		{
			case '+':
				operation = new Add();	// case마다 객체를 다르게 생성해 연산을 수행
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
