package ������;
import java.sql.*;
public class DataBaseConnection {
	// ��Ҫ���ܾ����������ݿ⡢�ر����ݿ�  
	 
	    //�������ݿ�������  
	    private final String DBDRIVER = "com.mysql.jdbc.Driver" ;  
	    //�������ݿ�����URL  
	    private final String DBURL = "jdbc:mysql://localhost:3306/������?useUnicode=true&characterEncoding=UTF-8";  
	    //�������ݿ������û���  
	    private final String DBUSER = "root" ;  
	    //�������ݿ���������  
	    private final String DBPASSWORD = "123456" ;  
	    //�������ݿ����Ӷ���  
	    private Connection conn = null ;  
	    //���췽������������  
	    public DataBaseConnection(){  
	        try{  
	        	
	            Class.forName(DBDRIVER) ;  
	            this.conn = DriverManager.getConnection(DBURL,DBUSER,DBPASSWORD) ;    
	        }  
	        catch (Exception e){  
	            System.out.println("��������ʧ��");  
	        }  
	    }  
	    // ȡ�����ݿ�����  
	    public Connection getConnection(){  
	        return conn ;  
	     
	    }  
	    // �ر����ݿ�����  
	    public void close(){  
	        try{  
	            conn.close() ;  
	        }catch (Exception e){  
	            System.out.println("���ݿ����ӹر�ʧ��");  
	        }         
	    }  
	} 


