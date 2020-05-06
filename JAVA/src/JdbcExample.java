import java.rmi.server.ExportException;
import java.sql.*;

public class JdbcExample
{

    public static void main(String[] args)
    {
        try
        {
            Class.forName("com.mysql.jdbc.Driver");
            Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/sampledb","root","");
            System.out.println("DB 연결 완료");
        }
        catch(ClassNotFoundException e)
        {
            System.out.println("JDBC 드라이버 로드 에러");
        }
        catch(SQLException e)
        {
            System.out.println("DB 연결에러");
        }
    }
}
