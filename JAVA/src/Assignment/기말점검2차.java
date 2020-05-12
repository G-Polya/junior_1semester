package Assignment;

import java.io.*;
import java.util.*;


public class �⸻����2�� 
{
	// �й�, ����, �⼮, ����, �߰�, �⸻�� �Է¹޾� csv���Ϸ� �����ϴ� �޼ҵ�
	public static void make_inputCSV(List<List<String>> table, String title, String filepath)
	{
		//int resultCount = 0;
		try
		{
			BufferedWriter fw = new BufferedWriter(new FileWriter(filepath+"\\"+title+".csv", true)); // ������ ����� BufferedWriter ��ü
			
			
			// ù row�� �й�, �̸�, �⼮,����, �߰�, �⸻
			fw.write("�й�,�̸�,�⼮,����,�߰�,�⸻");
			fw.newLine();
			
			for (List<String> student : table)
			{
				fw.write(student.get(0)+","+student.get(1) +","+student.get(2)+","+student.get(3)+","+student.get(4)+","+student.get(5));	// ���� ����
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
	
	// �й�, ����, �⼮, ����, �߰�, �⸻�� �Է¹޾� csv���Ϸ� �����ϴ� �޼ҵ�
	public static void make_outputCSV(List<List<String>> table, String title, String filepath)
	{
		//int resultCount = 0;
		try
		{
			BufferedWriter fw = new BufferedWriter(new FileWriter(filepath+"\\"+title+".csv", true));// ������ ����� BufferedWriter ��ü
			
			// ù row�� �й�, �̸�, �⼮, �߰�, �⸻, �հ�, ���
			fw.write("�й�,�̸�,�⼮,����,�߰�,�⸻,�հ�,���");
			fw.newLine();
			
			for (List<String> student : table)
			{
				fw.write(student.get(0)+","+student.get(1) +","+student.get(2)+","+student.get(3)+","+student.get(4)+","+student.get(5)+","+student.get(6)+","+student.get(7)); // ���� ����
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
	
	// ��������, ����� ���Ҷ� ����
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
	
	// ����� ��ȯ�ϴ� �޼ҵ�
	// �հ踦 �Է����� �޾� �� �հ�� ����� �̷���� HashMap�� ��ȯ�Ѵ�.
	public static HashMap<String, Integer> win_number(String[] sums)
	{
		// ���� �հ踦 �Է¹޾Ƽ� �������ش�. 
		int[] input = new int[sums.length];
		for(int i = 0; i < sums.length;i++)
			input[i] = Integer.parseInt(sums[i]);
		selectionSort(input, input.length);
		
		// int���� �հ���� String���� �ٲ��ִ� �����̴�. 
		String[] temp = new String[input.length];
		for(int i = 0; i< input.length;i++)
			temp[i] = Integer.toString(input[i]);
		
		
		// �ؽø� ��ü�� �����ؼ� �հ迡 �ش��ϴ� ����� �Է��Ѵ�.
		// ���ĵǾ� �����Ƿ� ū ������ ���� ����� value�� ����
		HashMap<String, Integer> wins = new HashMap<String, Integer>();	 
		for(int i = 0; i< input.length;i++)
		{
			wins.put(temp[i], i+1);
		}
		

		return wins;
		
		
	}
	
	// CSV������ �о���� �޼ҵ�
	public static Scanner readCSV(String filename)
	{
		Scanner inputTxt = null;
		try
		{
			inputTxt = new Scanner(new FileReader(filename)).useDelimiter("\n");	// ���๮�ڷ� ���еɰ�
			
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}
		return inputTxt;
	}
	
	public static void main(String[] args)
	{
	//	 �ֿܼ� ������ �Է��Ͽ� inputFile.csv�� �����ϴ� �����̴�.
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("�л� ���� �Է��ϼ��� (20�� �̻� �Է��ϼ���)>> ");
		int size = scanner.nextInt();
		
		List<List<String>> student_table = new ArrayList<List<String>>();	// �л����� ������ �Էµ� List
		
		System.out.println("�й�, ����, �⼮, ����, �߰�, �⸻ ������ �Է��ϼ���");
		
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
		
		Scanner inputScanner = readCSV(inputFile);		// inputFile.csv �о����
		List<String> temp = new ArrayList<String>();	// inputFile�� ������ ���� ��ü
		while(inputScanner.hasNext())
		{
			temp.add(inputScanner.next());	
		}
		
		// �հ踦 �����ϱ� ���� ����
		List<String[]> temp_table = new ArrayList<String[]>();
		
		for(int i = 1; i < temp.size();i++)
		{
			String[] data = temp.get(i).split(",");		// ,�� �������� ����
			data[5] = data[5].replaceAll("(\r\n|\r|\n|\n\r)", "");	// ������ �̷������ ������  ������ �ָ������� ��찡 ����
			
			String sum = Integer.toString(Integer.parseInt(data[2]) + Integer.parseInt(data[3]) + Integer.parseInt(data[4])+ Integer.parseInt(data[5]));
			
			
			String[] output = {data[0],data[1],data[2],data[3],data[4],data[5], sum};	// row 1�� = output�̴�. �й�, ����, �⼮, ����, �߰�, �⸻, �հ�� ������
			temp_table.add(output);		// �� row���� ����
		}
		
		
		String[] sums = new String[temp_table.size()];	// �հ�鸸���� ������ �迭
		for(int i = 0; i < temp_table.size();i++)
		{
			sums[i] = temp_table.get(i)[6];
		}
		
		
		HashMap<String, Integer> wins = win_number(sums);	// �հ�� ����� ���� �ִ� �ؽø��� ����
		
		
		List<List<String>> output_table = new ArrayList<List<String>>();
		for(int i = 0; i< temp_table.size();i++)
		{
			List<String> output = new ArrayList<String>();	// table�� �̷�� row 
			output.add(temp_table.get(i)[0]);	// �й�
			output.add(temp_table.get(i)[1]);	// ����
			output.add(temp_table.get(i)[2]);	// �⼮
			output.add(temp_table.get(i)[3]);	// ����
			output.add(temp_table.get(i)[4]);	// �߰�
			output.add(temp_table.get(i)[5]);	// �⸻
			output.add(temp_table.get(i)[6]);	// �հ�
			output.add(Integer.toString(wins.get(temp_table.get(i)[6])));	// ���. �հ迡 �ش��ϴ� ����� output�� ������ ���ҷ� �����Ѵ�. 
			
			output_table.add(output);	// table�� row�� ����
		}
		
		make_outputCSV(output_table,"outputFile","C:\\Users\\wlska\\Documents\\junior_1semester\\JAVA\\src\\Assignment");
		System.out.println("��!");
	}
	
}
