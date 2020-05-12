package Assignment;
import java.util.Scanner;

class Student
{
	private String id_num;
	private String name;
	private int attendance;
	private int mid_term;
	private int final_term;
	
	public Student(String id_num, String name, int attendance, int mid_term, int final_term)
	{
		this.id_num = id_num;
		this.name = name;
		this.attendance = attendance;
		this.mid_term = mid_term;
		this.final_term = final_term;
	}
	
	public String get_Id()
	{
		return id_num;
	}
	
	public String get_Name()
	{
		return name;
	}
	
	public int get_Attendance()
	{
		return attendance;
	}
	
	public int get_Midterm()
	{
		return mid_term;
	}
	
	public int get_Fianlterm()
	{
		return final_term;
	}
}

public class 기말점검2차 
{
	public static void main(String[] args)
	{
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("학생 수를 입력하세요 >> ");
		int size = scanner.nextInt();
		
		
		Student[] students = new Student[size];
		boolean flag = true;
		System.out.println("학번, 성명, 출석, 과제, 중간, 기말 순으로 20명 이상 입력하세요(stop을 입력하면 그만입력합니다)");
		for(int i = 0; i< students.length; i ++)
		{	String id_num = scanner.next();
			if(id_num.equals("stop"))
				flag = false;
			
			String name = scanner.next();
			int attendance = scanner.nextInt();
			int mid_term = scanner.nextInt();
			int final_term = scanner.nextInt();
			
			students[i] = new Student(id_num, name, attendance, mid_term, final_term);
			
		}
		
		for(int k = 0; k<students.length;k++)
		{
			System.out.println(students[k].get_Attendance());
		}
	}
	
}
