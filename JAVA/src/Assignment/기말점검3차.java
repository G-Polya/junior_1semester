package Assignment;
import Assignment.*;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.rmi.server.ExportException;
import java.sql.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

// http://www.munsam.info/xe/JAVA/517609
// https://sourcestudy.tistory.com/325

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
			
			// 쿼리에 인자 부여
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
	
	public static void main(String[] args)
	{
		Create_Database_Table db = new Create_Database_Table();
		String inputFile = "C:\\Users\\wlska\\Documents\\junior_1semester\\JAVA\\src\\Assignment\\inputFile.csv";
		
		Scanner inputScanner = 기말점검2차.readCSV(inputFile);		// inputFile.csv 읽어오기
		
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
		
		
		HashMap<String, Integer> wins = 기말점검2차.win_number(sums);	// 합계와 등수가 같이 있는 해시맵을 생성
		
		
		List<List<String>> output_table = new ArrayList<List<String>>();
		for(int i = 0; i< temp_table.size();i++)
		{
			List<String> output = new ArrayList<String>();	// table을 이루는 row 
			String no = temp_table.get(i)[0];				// 학번
			String name = temp_table.get(i)[1];				// 성명
			int attend = Integer.parseInt(temp_table.get(i)[2]);	// 출석
			int assign = Integer.parseInt(temp_table.get(i)[3]);	// 과제
			int mid_term = Integer.parseInt(temp_table.get(i)[4]);	// 중간
			int final_term = Integer.parseInt(temp_table.get(i)[5]);	// 기말
			int sum = Integer.parseInt(temp_table.get(i)[6]);	// 합계
			int ranking = wins.get(temp_table.get(i)[6]);		// 등수
			
			output.add(no);	
			output.add(name);	
			output.add(Integer.toString(attend));	
			output.add(Integer.toString(assign));	
			output.add(Integer.toString(mid_term));	
			output.add(Integer.toString(final_term));	
			output.add(Integer.toString(sum));	
			output.add(Integer.toString(ranking));	// 등수. 합계에 해당하는 등수를 output의 마지막 원소로 저장한다. 
			
			output_table.add(output);	// table에 row를 저장
			db.insert_toTable("test", "student", no, name, attend, assign, mid_term, final_term,sum,ranking);
		}
		
		기말점검2차.make_outputCSV(output_table,"outputFile","C:\\Users\\wlska\\Documents\\junior_1semester\\JAVA\\src\\Assignment");
		

	}
}
