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
            System.out.println("DB ���� �Ϸ�");
        }
        catch(ClassNotFoundException e)
        {
            System.out.println("JDBC ����̹� �ε� ����");
        }
        catch(SQLException e)
        {
            System.out.println("DB ���ῡ��");
        }
    }
}
