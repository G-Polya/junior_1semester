//2016112158 �����
import java.io.*;
import java.util.*;

public class Practice9 
{
	// ��ġ��, ����ġ ����, �����ð� ����ϴ� �޼ҵ�
	static void compare(String refDNA, String myDNA, int k, int threshold,long time)
	{
		try
		{
			BufferedWriter fw = new BufferedWriter(new FileWriter("C:\\Users\\wlska\\Documents\\junior_1semester\\JAVA\\src\\"+k+"_information.txt",true));	// ��ġ���� ����ġ����, �����ð��� �Էµ� ���ϰ�ü
			
			PrintWriter pw = new PrintWriter(fw,true);	// ������ ����� �ʰ� �̾ �Էµ� �� �ֵ���
			
			int N = refDNA.length();
			int M = myDNA.length();
			
			int mismatches=0;	// refDNA�� myDNA�� ����ġ�ϴ� ��Ŭ����Ÿ�̵� ����
			
			// brute-force�� ���� mismatches�� ���Ѵ�
			for(int i = 0; i<=N-M;i++)
			{
				int j;
				for(j = 0; j<M;j++)
					if(myDNA.charAt(j) != refDNA.charAt(i+j))
					{
						mismatches++;
						continue;
					}
			}
			
			double result = (M-mismatches) /(double)M * 100;	// ��ġ��
			
			// ���Ͽ� �Է�
			pw.write("threshold�� "+threshold+" �� �� : \n");
			pw.write(String.format("myDNA�� refDNA�� ��ġ�ϴ� ���� : %.2f�ۼ�Ʈ , ����ġ ���� : %d\n", result, mismatches));
			pw.write("������ "+time/1000+"�� �ҿ��\n");
			pw.write("=============================\n");
			pw.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
	
	// ��ġ��, ����ġ ������ ����ϴ� �޼ҵ�
	static void compare(String refDNA, String myDNA, int k)
	{
		try
		{
			BufferedWriter fw = new BufferedWriter(new FileWriter("C:\\Users\\wlska\\Documents\\junior_1semester\\JAVA\\src\\information.txt",true));	// ��ġ���� ����ġ����, �����ð��� �Էµ� ���ϰ�ü
			
			PrintWriter pw = new PrintWriter(fw,true);	// ������ ����� �ʰ� �̾ �Էµ� �� �ֵ���
			
			int N = refDNA.length();
			int M = myDNA.length();
			
			int mismatches=0;	// refDNA�� myDNA�� ����ġ�ϴ� ��Ŭ����Ÿ�̵� ����
			
			// brute-force�� ���� mismatches�� ���Ѵ�
			for(int i = 0; i<=N-M;i++)
			{
				int j;
				for(j = 0; j<M;j++)
					if(myDNA.charAt(j) != refDNA.charAt(i+j))
					{
						mismatches++;
						continue;
					}
			}
			
			double result = (M-mismatches) /(double)M * 100;	// ��ġ��
			
			// ���Ͽ� �Է�
			pw.write(refDNA+"�� "+myDNA+"�� ��:\n");
			pw.write(String.format("myDNA�� refDNA�� ��ġ�ϴ� ���� : %.2f�ۼ�Ʈ , ����ġ ���� : %d\n", result, mismatches));
			pw.write("=============================\n");
			pw.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
	
	//threshold�� ������ �ִ°� �����̴�.
	// �ʹ� ���� ���� �ָ� string subscript out of range������ ��Ÿ����
	// �ʹ� ū ���� �ָ� myDNA�� refDNA�� ���� ��ġ��
	static int brute_force_matching(String refDNA, String shortRead, int threshold)
	{
		int M = shortRead.length();
		int N = refDNA.length();
		int i;
		for(i = 0; i<=N-M;i++)
		{
			int j;
			int mismatches = 0;	// ��ġ���� �ʴ� ��Ŭ���� Ÿ�̵� ����
			
			for(j = 0; j<M;j++)
				if(shortRead.charAt(j)!= refDNA.charAt(i+j))
				{
					mismatches++;
					continue;
				}
			
			if(mismatches < threshold)
				return i;
		}
		
		return i;
	}
	
	static String trivial_Mapping(String refDNA, Vector<String> shortReads, int threshold)
	{
		String myDNA = refDNA;	// myDNA�� refDNA�� ���� ����ϴ�. 
		try 
		{
			
			int number = 0;
			for(String shortRead:shortReads)	// ������ shortRead�� ���ؼ�
			{
				int index = brute_force_matching(refDNA,shortRead, threshold);	// ���� mismatch�� ���� �ε����� �����´�. 
				System.out.println(number+" ��° shortRead�� "+index+"���� ��Ÿ��");
				number++;
				for(int i = index; i< index+shortRead.length();i++)
				{
					char[] temp_char = new char[refDNA.length()];
					temp_char = myDNA.substring(0, refDNA.length()).toCharArray();
					//System.out.println(refDNA.length());
					temp_char[i] = shortRead.charAt(i-index);	// myDNA���� index ~ (index+length)�� �ش��ϴ� �κ��� shortRead�� �ٲ��ش�.
					myDNA = String.valueOf(temp_char);
				}
			}
			
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		return myDNA;
		
	}
	
	
	public static void main(String[] args)
	{
		try
		{
			
			//int k = 60, n = 15000;
			Scanner scanner = new Scanner(System.in);
			System.out.print("ShortRead�� ���� k�� �Է��ϼ��� >> ");
			int k = scanner.nextInt();
			System.out.print("ShortRead�� ���� n�� �Է��ϼ��� >> ");
			int n = scanner.nextInt();
			
			String refDNA_path = "C:\\Users\\wlska\\Documents\\junior_1semester\\JAVA\\src\\referenceDNA.txt";	//referenceDNA �о���� ��ü
			BufferedReader fileReader = new BufferedReader(new FileReader(refDNA_path));
			String refDNA = fileReader.readLine();	// referenceDNA������ ����� ��Ʈ��
			
			Vector<String> shortReads = new Vector<String>();
			for(int i = 0; i< n;i++)
			{
				// shortRead�� �о���� ��ü
				BufferedReader reader = new BufferedReader(new FileReader("C:\\Users\\wlska\\source\\repos\\not_github_test\\not_github_test\\"+k+"_shortRead\\shortRead_"+i+".txt"));	
				String shortRead = reader.readLine();
				
				shortReads.add(shortRead);	// shortReads�� shortRead����.
				reader.close();
			}
			
			
			for(int threshold = 15; threshold < 20; threshold++)
			{
				BufferedWriter fw = new BufferedWriter(new FileWriter("C:\\Users\\wlska\\Documents\\junior_1semester\\JAVA\\src\\"+k+"_"+threshold+"_myDNA.txt"));	// myDNA�� �ԷµǴ� ��ü
				long start = System.currentTimeMillis();
				String myDNA = trivial_Mapping(refDNA, shortReads, threshold);	// myDNA�� �����Ѵ�.
				long end = System.currentTimeMillis();
				long elapsed_time = end-start;
				fw.write(myDNA);
				
				compare(refDNA, myDNA,k, threshold, elapsed_time);
				fw.close();
				
			}

			//�̹� ���Ϸ� �����ϴ� myDNA�� refDNA�� ���Ҷ�
			BufferedReader fin = new BufferedReader(new FileReader("C:\\Users\\wlska\\Documents\\junior_1semester\\JAVA\\src\\"+k+"_"+14+"_myDNA.txt"));
			String myDNA_14 = fin.readLine();
			compare(refDNA, myDNA_14, k);
			fin.close();
			
			fileReader.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}

}
