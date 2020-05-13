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
	
	// �����ͺ��̽� ����
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
	
	// �����ͺ��̽��� �ִ��� Ȯ���ϰ�, ������ �����ͺ��̽� ���� �� �����ͺ��̽� ��ȯ
	public void CreateOrChangeDatabase(String dbName)
	{
		try
		{
			String dbSql = "SELECT * FROM Information_schema.SCHEMATA WHERE SCHEMA_NAME = ?";
			pstmt = conn.prepareStatement(dbSql);
			pstmt.setString(1, dbName);
			rs = pstmt.executeQuery();
			
			// �����ͺ��̽��� ���ٸ� �����ͺ��̽� ����
			if(!rs.next())
			{
				Statement stmt = conn.createStatement();
				String sql = "create database "+dbName;
				boolean re = stmt.execute(sql);
				if(!re)
					System.out.println("�����ͺ��̽� ���� ����");
				stmt.close();
			}
			// �����ͺ��̽��� ��ȯ (use database)
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
	
	// ���̺��� �ִ��� Ȯ���ϰ� ������ ����
	public void CreateTable(String dbName, String tName)
	{
		try
		{
			//�����ͺ��̽� ���� �� ��ȯ
			CreateOrChangeDatabase(dbName);
			
			//information_schecma.tables�� ���̺��� �������� Ȯ��
			String tableSql = "SELECT table_name FROM information_schema.tables where table_schema = ? and table_name = ?";
			pstmt = conn.prepareStatement(tableSql);
			pstmt.setString(1,  dbName);
			pstmt.setString(2,  tName);
			rs = pstmt.executeQuery();
			
			// ���̺��� ���ٸ� ���̺� ����
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
			
			// ������ ���� �ο�
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

public class �⸻����3�� 
{
	
	public static void main(String[] args)
	{
		Create_Database_Table db = new Create_Database_Table();
		String inputFile = "C:\\Users\\wlska\\Documents\\junior_1semester\\JAVA\\src\\Assignment\\inputFile.csv";
		
		Scanner inputScanner = �⸻����2��.readCSV(inputFile);		// inputFile.csv �о����
		
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
		
		
		HashMap<String, Integer> wins = �⸻����2��.win_number(sums);	// �հ�� ����� ���� �ִ� �ؽø��� ����
		
		
		List<List<String>> output_table = new ArrayList<List<String>>();
		for(int i = 0; i< temp_table.size();i++)
		{
			List<String> output = new ArrayList<String>();	// table�� �̷�� row 
			String no = temp_table.get(i)[0];				// �й�
			String name = temp_table.get(i)[1];				// ����
			int attend = Integer.parseInt(temp_table.get(i)[2]);	// �⼮
			int assign = Integer.parseInt(temp_table.get(i)[3]);	// ����
			int mid_term = Integer.parseInt(temp_table.get(i)[4]);	// �߰�
			int final_term = Integer.parseInt(temp_table.get(i)[5]);	// �⸻
			int sum = Integer.parseInt(temp_table.get(i)[6]);	// �հ�
			int ranking = wins.get(temp_table.get(i)[6]);		// ���
			
			output.add(no);	
			output.add(name);	
			output.add(Integer.toString(attend));	
			output.add(Integer.toString(assign));	
			output.add(Integer.toString(mid_term));	
			output.add(Integer.toString(final_term));	
			output.add(Integer.toString(sum));	
			output.add(Integer.toString(ranking));	// ���. �հ迡 �ش��ϴ� ����� output�� ������ ���ҷ� �����Ѵ�. 
			
			output_table.add(output);	// table�� row�� ����
			db.insert_toTable("test", "student", no, name, attend, assign, mid_term, final_term,sum,ranking);
		}
		
		�⸻����2��.make_outputCSV(output_table,"outputFile","C:\\Users\\wlska\\Documents\\junior_1semester\\JAVA\\src\\Assignment");
		

	}
}
