import java.sql.*;

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
            conn = DriverManager.getConnection("jdbc:mariadb://localhost:3306/mysql", "root", "skyss123");
            System.out.println("root로 접속했습니다.");
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
                System.out.println(dbName+" 데이터 베이스가 생성되었습니다.");
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
            System.out.println("Input Complete!");
        }
        catch(SQLException e)
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

