package ������;
import java.sql.PreparedStatement;  
import java.sql.ResultSet;  
import java.util.ArrayList;  
import java.util.List;

public class UserDAOImpl implements UserDAO{

	public void insert(User user) throws Exception {  
        String sql = "INSERT INTO user(�û���,���룬�ֻ����룬�Ա�) VALUES(?,?,?,?)" ;  
        PreparedStatement pstmt = null ;  
        DataBaseConnection dbc = null ;  
        // ������������ݿ�ľ������  
        try{  
            // �������ݿ�  
            dbc = new DataBaseConnection() ;  
            pstmt = dbc.getConnection().prepareStatement(sql) ;  
            pstmt.setString(1, user.getUsername());  
            pstmt.setString(2, user.getUserpassword());
            pstmt.setString(3,user.getPhone() );
            pstmt.setString(4, user.getSex());
            // �������ݿ���²���  
            pstmt.executeUpdate() ;  
            pstmt.close() ;  
        }catch (Exception e){  
            throw new Exception("���������쳣") ;  
        }  
        finally{  
            // �ر����ݿ�����  
            dbc.close() ;  
        }  
    }  
    //�޸Ĳ���  
    public void update(User user) throws Exception {  
        String sql = "UPDATE user SET �û���=?,����=? WHERE �û�ID=?" ;  
        PreparedStatement pstmt = null ;  
        DataBaseConnection dbc = null ;  
        // ������������ݿ�ľ������  
        try{  
            // �������ݿ�  
            dbc = new DataBaseConnection() ;  
            pstmt = dbc.getConnection().prepareStatement(sql) ;           
            pstmt.setString(1, user.getUsername());  
            pstmt.setString(2, user.getUserpassword());  
            pstmt.setInt(3,user.getUserid());  
            // �������ݿ���²���  
            pstmt.executeUpdate() ;  
            pstmt.close() ;  
        }  
        catch (Exception e){  
            throw new Exception("���������쳣") ;  
        }  
        finally{  
            // �ر����ݿ�����  
            dbc.close() ;  
        }  
    }  
    //ɾ������  
    public void delete(int userid) throws Exception {  
        String sql = "DELETE FROM �û� WHERE �û�id=?" ;  
        PreparedStatement pstmt = null ;  
        DataBaseConnection dbc = null ;  
        // ������������ݿ�ľ������  
        try{  
            // �������ݿ�  
            dbc = new DataBaseConnection() ;  
            pstmt = dbc.getConnection().prepareStatement(sql) ;           
            pstmt.setInt(1,userid) ;  
            // �������ݿ���²���  
            pstmt.executeUpdate() ;  
            pstmt.close() ;  
        }catch (Exception e){  
            throw new Exception("���������쳣") ;  
        }  
        finally{  
            // �ر����ݿ�����  
            dbc.close() ;  
        }  
    }  
    //��ID��ѯ  
    public User queryById(int userid) throws Exception {  
        User user = null ;  
        String sql = "SELECT * FROM �û� WHERE �û�id=?" ;  
        PreparedStatement pstmt = null ;  
        DataBaseConnection dbc = null ;  
        // ������������ݿ�ľ������  
        try{  
            // �������ݿ�  
            dbc = new DataBaseConnection() ;  
            pstmt = dbc.getConnection().prepareStatement(sql) ;           
            pstmt.setInt(1, userid);  
            // �������ݿ��ѯ����  
            ResultSet rs = pstmt.executeQuery() ;  
            if(rs.next())  
            {  
                // ��ѯ�����ݣ�֮�󽫲�ѯ�������ݸ�ֵ��user����  
                user = new User() ;  
                user.setUserid(rs.getInt(1));  
                user.setUsername(rs.getString(2));  
                user.setUserpassword(rs.getString(3));  
            }  
            rs.close() ;  
            pstmt.close() ;  
        }catch (Exception e){  
            throw new Exception("���������쳣") ;  
        }  
        finally{  
            // �ر����ݿ�����  
            dbc.close() ;  
        }  
        return user ;  
    }  
    public List<User> queryAll() throws Exception {  
        List<User> all = new ArrayList<User>() ;  
        String sql = "SELECT * FROM �û� " ;  
        PreparedStatement pstmt = null ;  
        DataBaseConnection dbc = null ;  
  
        // ������������ݿ�ľ������  
        try{  
            // �������ݿ�  
            dbc = new DataBaseConnection() ;  
            pstmt = dbc.getConnection().prepareStatement(sql) ;   
            // �������ݿ��ѯ����  
            ResultSet rs = pstmt.executeQuery() ;  
            while(rs.next()){  
                // ��ѯ�����ݣ�֮�󽫲�ѯ�������ݸ�ֵ��user����  
                User user = new User() ;  
                user.setUserid(rs.getInt(1));  
                user.setUsername(rs.getString(2));  
                user.setUserpassword(rs.getString(3));  
  
                // ����ѯ���������ݼ��뵽List����֮��  
                all.add(user) ;  
            }  
            rs.close() ;  
            pstmt.close() ;  
        }  
        catch (Exception e){  
            throw new Exception("���������쳣") ;  
        }  
        finally{  
            // �ر����ݿ�����  
            dbc.close() ;  
        }  
        return all ;  
    }  
}
