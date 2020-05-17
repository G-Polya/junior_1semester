//2016112158 김희수
import java.io.*;
import java.util.*;

public class Practice9 
{
	// 일치도, 불일치 개수, 복원시간 출력하는 메소드
	static void compare(String refDNA, String myDNA, int k, int threshold,long time)
	{
		try
		{
			BufferedWriter fw = new BufferedWriter(new FileWriter("C:\\Users\\wlska\\Documents\\junior_1semester\\JAVA\\src\\"+k+"_information.txt",true));	// 일치도와 불일치개수, 복원시간이 입력될 파일객체
			
			PrintWriter pw = new PrintWriter(fw,true);	// 파일을 덮어쓰지 않고 이어서 입력될 수 있도록
			
			int N = refDNA.length();
			int M = myDNA.length();
			
			int mismatches=0;	// refDNA와 myDNA의 불일치하는 뉴클레오타이드 개수
			
			// brute-force를 통해 mismatches를 구한다
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
			
			double result = (M-mismatches) /(double)M * 100;	// 일치도
			
			// 파일에 입력
			pw.write("threshold가 "+threshold+" 일 때 : \n");
			pw.write(String.format("myDNA와 refDNA가 일치하는 정도 : %.2f퍼센트 , 불일치 개수 : %d\n", result, mismatches));
			pw.write("복원에 "+time/1000+"초 소요됨\n");
			pw.write("=============================\n");
			pw.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
	
	// 일치도, 불일치 개수만 출력하는 메소드
	static void compare(String refDNA, String myDNA, int k)
	{
		try
		{
			BufferedWriter fw = new BufferedWriter(new FileWriter("C:\\Users\\wlska\\Documents\\junior_1semester\\JAVA\\src\\information.txt",true));	// 일치도와 불일치개수, 복원시간이 입력될 파일객체
			
			PrintWriter pw = new PrintWriter(fw,true);	// 파일을 덮어쓰지 않고 이어서 입력될 수 있도록
			
			int N = refDNA.length();
			int M = myDNA.length();
			
			int mismatches=0;	// refDNA와 myDNA의 불일치하는 뉴클레오타이드 개수
			
			// brute-force를 통해 mismatches를 구한다
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
			
			double result = (M-mismatches) /(double)M * 100;	// 일치도
			
			// 파일에 입력
			pw.write(refDNA+"와 "+myDNA+"를 비교:\n");
			pw.write(String.format("myDNA와 refDNA가 일치하는 정도 : %.2f퍼센트 , 불일치 개수 : %d\n", result, mismatches));
			pw.write("=============================\n");
			pw.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
	
	//threshold를 적절히 주는게 관건이다.
	// 너무 적은 수를 주면 string subscript out of range에러가 나타나고
	// 너무 큰 수를 주면 myDNA와 refDNA가 거의 일치함
	static int brute_force_matching(String refDNA, String shortRead, int threshold)
	{
		int M = shortRead.length();
		int N = refDNA.length();
		int i;
		for(i = 0; i<=N-M;i++)
		{
			int j;
			int mismatches = 0;	// 일치하지 않는 뉴클레오 타이드 개수
			
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
		String myDNA = refDNA;	// myDNA와 refDNA는 거의 비슷하다. 
		try 
		{
			
			int number = 0;
			for(String shortRead:shortReads)	// 각각의 shortRead에 대해서
			{
				int index = brute_force_matching(refDNA,shortRead, threshold);	// 가정 mismatch가 적은 인덱스를 가져온다. 
				System.out.println(number+" 번째 shortRead는 "+index+"부터 나타남");
				number++;
				for(int i = index; i< index+shortRead.length();i++)
				{
					char[] temp_char = new char[refDNA.length()];
					temp_char = myDNA.substring(0, refDNA.length()).toCharArray();
					//System.out.println(refDNA.length());
					temp_char[i] = shortRead.charAt(i-index);	// myDNA에서 index ~ (index+length)에 해당하는 부분을 shortRead로 바꿔준다.
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
			System.out.print("ShortRead의 길이 k를 입력하세요 >> ");
			int k = scanner.nextInt();
			System.out.print("ShortRead의 개수 n을 입력하세요 >> ");
			int n = scanner.nextInt();
			
			String refDNA_path = "C:\\Users\\wlska\\Documents\\junior_1semester\\JAVA\\src\\referenceDNA.txt";	//referenceDNA 읽어오는 객체
			BufferedReader fileReader = new BufferedReader(new FileReader(refDNA_path));
			String refDNA = fileReader.readLine();	// referenceDNA내용이 저장된 스트링
			
			Vector<String> shortReads = new Vector<String>();
			for(int i = 0; i< n;i++)
			{
				// shortRead를 읽어오는 객체
				BufferedReader reader = new BufferedReader(new FileReader("C:\\Users\\wlska\\source\\repos\\not_github_test\\not_github_test\\"+k+"_shortRead\\shortRead_"+i+".txt"));	
				String shortRead = reader.readLine();
				
				shortReads.add(shortRead);	// shortReads에 shortRead저장.
				reader.close();
			}
			
			
			for(int threshold = 15; threshold < 20; threshold++)
			{
				BufferedWriter fw = new BufferedWriter(new FileWriter("C:\\Users\\wlska\\Documents\\junior_1semester\\JAVA\\src\\"+k+"_"+threshold+"_myDNA.txt"));	// myDNA가 입력되는 객체
				long start = System.currentTimeMillis();
				String myDNA = trivial_Mapping(refDNA, shortReads, threshold);	// myDNA를 복원한다.
				long end = System.currentTimeMillis();
				long elapsed_time = end-start;
				fw.write(myDNA);
				
				compare(refDNA, myDNA,k, threshold, elapsed_time);
				fw.close();
				
			}

			//이미 파일로 존재하는 myDNA와 refDNA를 비교할때
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
