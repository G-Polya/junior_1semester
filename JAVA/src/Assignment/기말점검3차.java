package Assignment;

import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.sql.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;


class Create_Database_Table
{
	private Connection conn;
	private PreparedStatement pstmt;
	private ResultSet rs, rs2;

	// 데이터베이스 연결
	public Create_Database_Table()
	{
		try
		{
			Class.forName("org.mariadb.jdbc.Driver");
			conn = DriverManager.getConnection("jdbc:mariadb://localhost:3306/test", "testuser", "1234");
		}
		catch(Exception e)
		{
			System.out.println("DB connect eror : "+ e);
		}
	}

	// 데이터베이스가 있는지 확인하고, 없으면 데이터베이스 생성 후 데이터베이스 전환
	public void CreateOrChangeDatabase(String dbName)
	{
		try
		{
			String dbSql = "SELECT * FROM Information_schema.SCHEMATA WHERE SCHEMA_NAME = ?";
			pstmt = conn.prepareStatement(dbSql);
			pstmt.setString(1, dbName);
			rs = pstmt.executeQuery();

			// 데이터베이스가 없다면 데이터베이스 생성
			if(!rs.next())
			{
				Statement stmt = conn.createStatement();
				String sql = "create database "+dbName;
				boolean re = stmt.execute(sql);
				if(!re)
					System.out.println("데이터베이스 생성 실패");
				stmt.close();
			}
			// 데이터베이스를 전환 (use database)
			conn.setCatalog(dbName);
		}
		catch(Exception e)
		{
			System.out.println("CreateOrChangeDatabase Error : "+ e);
		}
		finally
		{
			try
			{
				if(rs!=null)
					rs.close();
				if(pstmt!=null)
					pstmt.close();
				if(conn!=null)
					pstmt.close();
			}
			catch(Exception e)
			{

			}
		}
	}

	// 테이블이 있는지 확인하고 없으면 생성
	public void CreateTable(String dbName, String tName)
	{
		try
		{
			//데이터베이스 생성 및 전환
			CreateOrChangeDatabase(dbName);

			//information_schecma.tables로 테이블의 존재유무 확인
			String tableSql = "SELECT table_name FROM information_schema.tables where table_schema = ? and table_name = ?";
			pstmt = conn.prepareStatement(tableSql);
			pstmt.setString(1,  dbName);
			pstmt.setString(2,  tName);
			rs = pstmt.executeQuery();

			// 테이블이 없다면 테이블 생성
			if(!rs.next())
			{
				Statement stmt = conn.createStatement();
				String sql = "create table "+ tName
						+"("
						+"no int primary key,"
						+"name varchar(10),"
						+"attendance int,"
						+"assignment int,"
						+"mid_term int,"
						+"final_term int,"
						+"sum int,"
						+"ranking int"
						+")";

				rs2 = stmt.executeQuery(sql);
				stmt.close();
				System.out.println(rs2);
			}
		}
		catch(Exception e)
		{
			System.out.println("CreateTable error : "+ e);
		}
		finally
		{
			try
			{

				if(rs!=null)rs.close();

				if(pstmt!=null)pstmt.close();

				if(conn!=null)pstmt.close();

			}
			catch (Exception e)
			{

			}
		}
	}

	public void insert_toTable(String dbName, String tName, String no, String name, int attend, int assign, int _mid, int _final,int sum, int ranking)
	{
		try
		{
			CreateTable(dbName, tName);
			String insertSql = "insert into "+tName+" value (?,?,?,?,?,?,?,?)";
			pstmt = conn.prepareStatement(insertSql);

			pstmt.setString(1, no);
			pstmt.setString(2,  name);
			pstmt.setInt(3, attend);
			pstmt.setInt(4, assign);
			pstmt.setInt(5, _mid);
			pstmt.setInt(6, _final);
			pstmt.setInt(7, sum);
			pstmt.setInt(8,  ranking);

			rs = pstmt.executeQuery();

		}
		catch(Exception e)
		{
			System.out.println("Insert error : "+ e);
		}
		finally
		{
			try
			{
				if(rs!=null)rs.close();

				if(pstmt!=null)pstmt.close();

				if(conn!=null)pstmt.close();
			}
			catch(Exception e)
			{

			}
		}
	}
}

public class 기말점검3차
{
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

	public static void main(String[] args)
	{
		Create_Database_Table db = new Create_Database_Table();
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
			String no = temp_table.get(i)[0];
			String name = temp_table.get(i)[1];
			int attend = Integer.parseInt(temp_table.get(i)[2]);
			int assign = Integer.parseInt(temp_table.get(i)[3]);
			int mid_term = Integer.parseInt(temp_table.get(i)[4]);
			int final_term = Integer.parseInt(temp_table.get(i)[5]);
			int sum = Integer.parseInt(temp_table.get(i)[6]);
			int ranking = wins.get(temp_table.get(i)[6]);

			output.add(no);	// 학번
			output.add(name);	// 성명
			output.add(Integer.toString(attend));	// 출석
			output.add(Integer.toString(assign));	// 과제
			output.add(Integer.toString(mid_term));	// 중간
			output.add(Integer.toString(final_term));	// 기말
			output.add(Integer.toString(sum));	// 합계
			output.add(Integer.toString(ranking));	// 등수. 합계에 해당하는 등수를 output의 마지막 원소로 저장한다.

			output_table.add(output);	// table에 row를 저장
			db.insert_toTable("test", "student", no, name, attend, assign, mid_term, final_term,sum,ranking);
		}

		make_outputCSV(output_table,"outputFile","C:\\Users\\wlska\\Documents\\junior_1semester\\JAVA\\src\\Assignment");

//		String no = "2016112158";
//		String name = "kim";
//		int attend = 10;
//		int assign = 20;
//		int mid_term = 35;
//		int final_term = 35;	
//		int sum = attend+assign+mid_term+final_term;
//		int ranking = 1;
//		db.insert_toTable("test", "student", no, name, attend, assign, mid_term, final_term, sum, ranking);
	}
}
