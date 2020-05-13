
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
			Class.forName("org.mariadb.jdbc.Driver");		// 드라이버 로드
			
			connection =  DriverManager.getConnection("jdbc:mariadb://localhost:3306/test", "testuser", "1234");	// DB에 연결. mysql:데이터베이스 이름, root:사용자이름, skyss123:비밀번호
	
			if(connection != null)
				System.out.println("DB접속 성공");
			
			statement = connection.createStatement();
			ResultSet resultSet = statement.executeQuery("select * from student;");		// 쿼리문. student 테이블의 모든 정보 가져오기 
			System.out.println(" 번호 이름");
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
			System.out.println("드라이버 로드 실패");
		}
		catch(SQLException e)
		{
			System.out.println("DB 접속 실패");
			e.printStackTrace();
		}
    }
}