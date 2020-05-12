package Assignment;

import java.io.*;
import java.util.*;


public class 기말점검2차 
{
	// 학번, 성명, 출석, 과제, 중간, 기말을 입력받아 csv파일로 저장하는 메소드
	public static void make_inputCSV(List<List<String>> table, String title, String filepath)
	{
		//int resultCount = 0;
		try
		{
			BufferedWriter fw = new BufferedWriter(new FileWriter(filepath+"\\"+title+".csv", true)); // 정보가 저장될 BufferedWriter 객체
			
			
			// 첫 row는 학번, 이름, 출석,과제, 중간, 기말
			fw.write("학번,이름,출석,과제,중간,기말");
			fw.newLine();
			
			for (List<String> student : table)
			{
				fw.write(student.get(0)+","+student.get(1) +","+student.get(2)+","+student.get(3)+","+student.get(4)+","+student.get(5));	// 정보 저장
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
	
	// 학번, 성명, 출석, 과제, 중간, 기말을 입력받아 csv파일로 저장하는 메소드
	public static void make_outputCSV(List<List<String>> table, String title, String filepath)
	{
		//int resultCount = 0;
		try
		{
			BufferedWriter fw = new BufferedWriter(new FileWriter(filepath+"\\"+title+".csv", true));// 정보가 저장될 BufferedWriter 객체
			
			// 첫 row는 학번, 이름, 출석, 중간, 기말, 합계, 등수
			fw.write("학번,이름,출석,과제,중간,기말,합계,등수");
			fw.newLine();
			
			for (List<String> student : table)
			{
				fw.write(student.get(0)+","+student.get(1) +","+student.get(2)+","+student.get(3)+","+student.get(4)+","+student.get(5)+","+student.get(6)+","+student.get(7)); // 정보 저장
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
	
	// 선택정렬, 등수를 정할때 사용됨
	private static void selectionSort(int[] input, int length)
	{
		int max;
		int tmp;
		for(int i =0; i<length-1;i++)
		{
			max = i;
			for(int j = i +1 ; j<length;j++)
			{
				if(input[j] > input[max])
					max = j;
			}
			tmp = input[i];
			input[i] = input[max];
			input[max] = tmp;
		}
	}
	
	// 등수를 반환하는 메소드
	// 합계를 입력으로 받아 그 합계와 등수로 이루어진 HashMap을 반환한다.
	public static HashMap<String, Integer> win_number(String[] sums)
	{
		// 먼저 합계를 입력받아서 정렬해준다. 
		int[] input = new int[sums.length];
		for(int i = 0; i < sums.length;i++)
			input[i] = Integer.parseInt(sums[i]);
		selectionSort(input, input.length);
		
		// int형인 합계들을 String으로 바꿔주는 과정이다. 
		String[] temp = new String[input.length];
		for(int i = 0; i< input.length;i++)
			temp[i] = Integer.toString(input[i]);
		
		
		// 해시맵 객체를 생성해서 합계에 해당하는 등수를 입력한다.
		// 정렬되어 있으므로 큰 수부터 작은 등수를 value로 가짐
		HashMap<String, Integer> wins = new HashMap<String, Integer>();	 
		for(int i = 0; i< input.length;i++)
		{
			wins.put(temp[i], i+1);
		}
		

		return wins;
		
		
	}
	
	// CSV파일을 읽어오는 메소드
	public static Scanner readCSV(String filename)
	{
		Scanner inputTxt = null;
		try
		{
			inputTxt = new Scanner(new FileReader(filename)).useDelimiter("\n");	// 개행문자로 구분될것
			
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}
		return inputTxt;
	}
	
	public static void main(String[] args)
	{
	//	 콘솔에 성적을 입력하여 inputFile.csv에 저장하는 과정이다.
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("학생 수를 입력하세요 (20명 이상 입력하세요)>> ");
		int size = scanner.nextInt();
		
		List<List<String>> student_table = new ArrayList<List<String>>();	// 학생들의 정보가 입력될 List
		
		System.out.println("학번, 성명, 출석, 과제, 중간, 기말 순으로 입력하세요");
		
		for(int i = 0; i<size;i++)
		{
			String id_num = scanner.next();
			String name = scanner.next();
			String attendance = scanner.next();
			String assignment = scanner.next();
			String mid_term = scanner.next();
			String final_term = scanner.next();
			
			List<String> student = new ArrayList<String>();
			student.add(id_num);
			student.add(name);
			student.add(attendance);
			student.add(assignment);
			student.add(mid_term);
			student.add(final_term);
			
			
			student_table.add(student);
		}
		
		make_inputCSV(student_table, "inputFile","C:\\Users\\wlska\\Documents\\junior_1semester\\JAVA\\src\\Assignment" );	

		String inputFile = "C:\\Users\\wlska\\Documents\\junior_1semester\\JAVA\\src\\Assignment\\inputFile.csv";
		
		Scanner inputScanner = readCSV(inputFile);		// inputFile.csv 읽어오기
		List<String> temp = new ArrayList<String>();	// inputFile의 정보를 담을 객체
		while(inputScanner.hasNext())
		{
			temp.add(inputScanner.next());	
		}
		
		// 합계를 저장하기 위한 과정
		List<String[]> temp_table = new ArrayList<String[]>();
		
		for(int i = 1; i < temp.size();i++)
		{
			String[] data = temp.get(i).split(",");		// ,를 기준으로 나눔
			data[5] = data[5].replaceAll("(\r\n|\r|\n|\n\r)", "");	// 개행이 이루어지는 곳에서  구분이 애매해지는 경우가 있음
			
			String sum = Integer.toString(Integer.parseInt(data[2]) + Integer.parseInt(data[3]) + Integer.parseInt(data[4])+ Integer.parseInt(data[5]));
			
			
			String[] output = {data[0],data[1],data[2],data[3],data[4],data[5], sum};	// row 1개 = output이다. 학번, 성명, 출석, 과제, 중간, 기말, 합계로 구성됨
			temp_table.add(output);		// 그 row들을 저장
		}
		
		
		String[] sums = new String[temp_table.size()];	// 합계들만으로 구성된 배열
		for(int i = 0; i < temp_table.size();i++)
		{
			sums[i] = temp_table.get(i)[6];
		}
		
		
		HashMap<String, Integer> wins = win_number(sums);	// 합계와 등수가 같이 있는 해시맵을 생성
		
		
		List<List<String>> output_table = new ArrayList<List<String>>();
		for(int i = 0; i< temp_table.size();i++)
		{
			List<String> output = new ArrayList<String>();	// table을 이루는 row 
			output.add(temp_table.get(i)[0]);	// 학번
			output.add(temp_table.get(i)[1]);	// 성명
			output.add(temp_table.get(i)[2]);	// 출석
			output.add(temp_table.get(i)[3]);	// 과제
			output.add(temp_table.get(i)[4]);	// 중간
			output.add(temp_table.get(i)[5]);	// 기말
			output.add(temp_table.get(i)[6]);	// 합계
			output.add(Integer.toString(wins.get(temp_table.get(i)[6])));	// 등수. 합계에 해당하는 등수를 output의 마지막 원소로 저장한다. 
			
			output_table.add(output);	// table에 row를 저장
		}
		
		make_outputCSV(output_table,"outputFile","C:\\Users\\wlska\\Documents\\junior_1semester\\JAVA\\src\\Assignment");
		System.out.println("끝!");
	}
	
}
