package Assignment;
import java.rmi.server.ExportException;
import java.sql.*;


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
											+"final_term int"
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
	
	public void insert_toTable(String dbName, String tName, String no, String name, int attend, int assign, int _mid, int _final)
	{
		try
		{
			CreateTable(dbName, tName);
			String insertSql = "insert into "+tName+" value (?,?,?,?,?,?)";
			pstmt = conn.prepareStatement(insertSql);
			
			pstmt.setString(1, no);
			pstmt.setString(2,  name);
			pstmt.setInt(3, attend);
			pstmt.setInt(4, assign);
			pstmt.setInt(5, _mid);
			pstmt.setInt(6, _final);
			
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
		String no = "2016112158";
		String name = "kim";
		int attend = 10;
		int assign = 20;
		int mid_term = 35;
		int final_term = 35;
		
		db.insert_toTable("test", "student", no, name, attend, assign, mid_term, final_term);
	}
}
