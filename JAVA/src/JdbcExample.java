
import java.rmi.server.ExportException;
import java.sql.*;

//http://egloos.zum.com/bmmania/v/2192065
public class JdbcExample
{
	public static void main(String[] args)
    {
		Connection connection = null;
		Statement statement = null;
		
		try
		{
			Class.forName("org.mariadb.jdbc.Driver");		// ����̹� �ε�
			
			connection =  DriverManager.getConnection("jdbc:mariadb://localhost:3306/test", "testuser", "1234");	// DB�� ����. mysql:�����ͺ��̽� �̸�, root:������̸�, skyss123:��й�ȣ
	
			if(connection != null)
				System.out.println("DB���� ����");
			
			statement = connection.createStatement();
			ResultSet resultSet = statement.executeQuery("select * from student;");		// ������. student ���̺��� ��� ���� �������� 
			System.out.println(" ��ȣ �̸�");
			System.out.println("---------");
			while(resultSet.next())
			{
				String id = resultSet.getString("id");
				String name = resultSet.getString("name");
				System.out.printf("%3s %s\n",id,name);
			}
		}
		catch(ClassNotFoundException e)
		{
			System.out.println("����̹� �ε� ����");
		}
		catch(SQLException e)
		{
			System.out.println("DB ���� ����");
			e.printStackTrace();
		}
    }
}