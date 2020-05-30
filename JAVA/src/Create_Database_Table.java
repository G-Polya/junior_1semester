import jdk.jshell.spi.ExecutionControlProvider;

import java.io.DataOutputStream;
import java.sql.*;
import java.util.HashMap;
import java.util.Vector;

class Create_Database_Table
{
    private Connection conn;
    private PreparedStatement pstmt;
    private ResultSet rs, rs2;
    private String dbName;
    private String tbName;
    private DataOutputStream out;

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

    public static HashMap<Integer, Integer> get_ranking(Vector<Integer> sums)
    {
        // 먼저 합계를 입력받아서 정렬해준다.
        int[] input = new int[sums.size()];
        for(int i = 0; i < sums.size();i++)
            input[i] = (Integer)sums.get(i);
        selectionSort(input, input.length);

        // int형인 합계들을 String으로 바꿔주는 과정이다.
//        String[] temp = new String[input.length];
//        for(int i = 0; i< input.length;i++)
//            temp[i] = Integer.toString(input[i]);


        // 해시맵 객체를 생성해서 합계에 해당하는 등수를 입력한다.
        // 정렬되어 있으므로 큰 수부터 작은 등수를 value로 가짐
        HashMap<Integer, Integer> ranking = new HashMap<Integer, Integer>();
        for(int i = 0; i< input.length;i++)
        {
            ranking.put(input[i], i+1);
        }


        return ranking;


    }

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
    public void CreateOrChangeDatabase(String dbName, DataOutputStream out)
    {
        this.out = out;
        this.dbName = dbName;
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
                System.out.println(dbName+" 데이터베이스가 생성되었습니다.");
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
    public void CreateTable(String tbName)
    {
        this.tbName = tbName;
        try
        {
            //데이터베이스 생성 및 전환

            //information_schecma.tables로 테이블의 존재유무 확인
            String tableSql = "SELECT table_name FROM information_schema.tables where table_schema = ? and table_name = ?";
            pstmt = conn.prepareStatement(tableSql);
            pstmt.setString(1,  dbName);
            pstmt.setString(2,  tbName);
            rs = pstmt.executeQuery();

            // 테이블이 없다면 테이블 생성
            if(!rs.next())
            {
                Statement stmt = conn.createStatement();
                String sql = "create table "+ tbName
                        +"("
                        +"no int primary key,"
                        +"name varchar(10),"
                        +"attendance int,"
                        +"assignment int,"
                        +"mid_term int,"
                        +"final_term int,"
                        +"sum int"
                        +")";

                rs2 = stmt.executeQuery(sql);
                stmt.close();
                System.out.println(rs2);
            }
            System.out.println(tbName+" 테이블이 생성되었습니다.");
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
    public void alter_Table(String column,String datatype)
    {
        try
        {
            String alterSql = "ALTER TABLE "+tbName+ " ADD "+ column +" "+datatype;
            pstmt = conn.prepareStatement(alterSql);
            rs = pstmt.executeQuery();
            rs.close();
            System.out.println("Alter Complete!");
            try
            {
                out.writeUTF("Alter Complete!");
            }
            catch (Exception e)
            {}

        }
        catch(SQLException e)
        {
            System.out.println("Alter Error : "+e);

            try
            {
                out.writeUTF("Alter Error : " + e);
            }
            catch(Exception err)
            {}

        }
    }

    public void update_table(String column, String condition, int sum, int ranking)
    {
        try
        {
            String updateSql = "update " + tbName +
                               " set "+column+" = "+ranking+
                               " where "+condition+" = "+sum;
            pstmt = conn.prepareStatement(updateSql);
            rs = pstmt.executeQuery();
            rs.close();
            System.out.println("Update Complete!");

            try
            {
                out.writeUTF("Update Complete!");
            }
            catch(Exception e)
            {}
        }
        catch(SQLException e)
        {
            System.out.println("Update Error : "+ e);
            try
            {
                out.writeUTF("Update Error : " + e);
            }
            catch(Exception err)
            {}

        }
    }

    public void select_id_name(int id, String name, String condition)
    {
        try
        {
            String selectSql = "select " + id + ", "+ name +
                    " from " + tbName;

            if(condition.length() != 0)
            {
                condition = " where "+condition;
                selectSql += condition;
            }

        }

    }



    public void insert_toTable(String id, String name, int attend, int assign, int _mid, int _final,int sum)
    {
        try
        {

            String insertSql = "insert into "+tbName+" value (?,?,?,?,?,?,?)";
            pstmt = conn.prepareStatement(insertSql);

            pstmt.setString(1, id);
            pstmt.setString(2,  name);
            pstmt.setInt(3, attend);
            pstmt.setInt(4, assign);
            pstmt.setInt(5, _mid);
            pstmt.setInt(6, _final);
            pstmt.setInt(7,sum);

            rs = pstmt.executeQuery();
            System.out.println("Input Complete!");

            // insert 성공시 클라이언트에 성공메시지 전달
            try
            {
                out.writeUTF("Input Complete!");

            }
            catch(Exception err)
            {

            }
        }
        catch(SQLException e)
        {
            System.out.println("Insert error : "+ e);

            // insert 실패시 클라이언트에 실패 메시지 전달
            try
            {
                out.writeUTF(e.getMessage()+"  Retry plz");
            }
            catch(Exception err)
            {

            }
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

    public int count_table()
    {
        int count = 0;
        try
        {
            String countSql = "SELECT COUNT(*) count FROM "+tbName;
            pstmt = conn.prepareStatement(countSql);

            rs = pstmt.executeQuery();
            rs.next();

            count = rs.getInt("count");
            rs.close();
            System.out.println("The number of rows : "+count);
            try
            {
                out.writeUTF("The number of rows : "+count);
            }
            catch(Exception err)
            {}
        }
        catch(SQLException e)
        {
            System.out.println("Count Error : "+e);
            try
            {
                out.writeUTF("Count Error : "+e);
            }
            catch(Exception err)
            {}
        }
        return count;
    }



    // sum이 주어지면 ranking을 반환하는 함수
    public int ranking_func(int sum)
    {
        int ranking = 0;
        try
        {
            String sum_Sql = "SELECT sum FROM "+tbName;
            pstmt = conn.prepareStatement(sum_Sql);
            rs = pstmt.executeQuery();
            Vector<Integer> sums = new Vector<Integer>();
            while(rs.next())
            {
                sums.add(rs.getInt("sum"));
            }
            HashMap<Integer, Integer> rankings = get_ranking(sums);
            ranking = rankings.get(sum);
        }
        catch(SQLException e)
        {
            System.out.println("Update Error : "+ e);
        }
        return ranking;
    }



}

