package Assignment;

import java.io.*;
import java.util.*;

class Student
{
	private String id_num;
	private String name;
	private String attendance;
	private String mid_term;
	private String final_term;
	
	public Student(String id_num, String name, String attendance, String mid_term, String final_term)
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
	
	public String get_Attendance()
	{
		return attendance;
	}
	
	public String get_Midterm()
	{
		return mid_term;
	}
	
	public String get_Fianlterm()
	{
		return final_term;
	}
}

public class 기말점검2차 
{
	public static void createCSV(List<Student> list, String title, String filepath)
	{
		//int resultCount = 0;
		try
		{
			BufferedWriter fw = new BufferedWriter(new FileWriter(filepath+"\\"+title+".csv", true));
			
			
			fw.write("학번,이름,출석,중간,기말");
			fw.newLine();
			
			for (Student student : list)
			{
				fw.write(student.get_Id()+","+student.get_Name() +","+student.get_Attendance()+","+student.get_Midterm()+","+student.get_Fianlterm());
				fw.newLine();
				//resultCount++;
			}
		
			fw.flush();
			fw.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
	
	public static Scanner readCSV(String filename)
	{
		Scanner inputTxt = null;
		try
		{
			inputTxt = new Scanner(new FileReader(filename)).useDelimiter(",");
			
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}
		return inputTxt;
	}
	
	public static void main(String[] args)
	{
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("학생 수를 입력하세요 >> ");
		int size = scanner.nextInt();
		
		List<Student> student_list = new ArrayList<Student>();
		
		System.out.println("학번, 성명, 출석, 과제, 중간, 기말 순으로 20명 이상 입력하세요");
		
		for(int i = 0; i<size;i++)
		{
			String id_num = scanner.next();
			String name = scanner.next();
			String attendance = scanner.next();
			String mid_term = scanner.next();
			String final_term = scanner.next();
			
			Student student = new Student(id_num, name, attendance, mid_term, final_term);
			student_list.add(student);
		}
		
//		기말점검2차.createCSV(student_list, "inputFile","C:\\Users\\wlska\\Documents\\junior_1semester\\JAVA\\src\\Assignment" );	
//		
		String inputFile = "C:\\Users\\wlska\\Documents\\junior_1semester\\JAVA\\src\\Assignment\\inputFile.csv";
		
		Scanner inputScanner = 기말점검2차.readCSV(inputFile);
		List<List<String>> output_list = ArrayList<List<String>>(); 
		while(inputScanner.hasNext())
		{
			
		}
		
	}
	
}
