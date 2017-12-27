package ������;

import java.util.ArrayList;
import java.util.List;
import java.sql.Date;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

public class orderDaoImp implements orderDao {

	@Override
	public void insert(order order) throws Exception {
		// TODO Auto-generated method stub
		String sql="insert into ����(�û�1,�û�2,��Ʒ1ID,��Ʒ2ID,����ʱ��)values(?,?,?,?,?)";
	    DataBaseConnection dbc=null;
	    PreparedStatement pstmt=null;
	    try 
	    {
	    	dbc=new DataBaseConnection();
	    	 pstmt = dbc.getConnection().prepareStatement(sql) ; 
	    	 pstmt.setString(1, order.getUsername1());
	    	 pstmt.setString(2, order.getUsername2());
	    	 pstmt.setString(3, order.getGoodsID1());
	    	 pstmt.setString(4, order.getGoodsID2());
	    	 pstmt.setDate(5, (Date) order.getTime());
	    	 pstmt.executeUpdate();
	    	 pstmt.close();
	    	
	    }catch (Exception e) {
			// TODO: handle exception
	    	throw new Exception("���������쳣") ;
	    }
	    	finally{  
	            // �ر����ݿ�����  
	            dbc.close() ;  
	         
		}

	}


	



	@Override
	public List<order> queryAll() throws Exception {
		// TODO Auto-generated method stub
		String sql="select * from ����";
		 DataBaseConnection dbc=null;
		 List<order> list=new ArrayList<order>();
		    PreparedStatement pstmt=null;
		    try 
		    {
		    	 dbc=new DataBaseConnection();
		    	 pstmt = dbc.getConnection().prepareStatement(sql) ; 
		    	
		    	
		    	 ResultSet rs=pstmt.executeQuery();
		    	 while(rs.next())
		    	 {
		    		 order order=new order();
		    		 order.setOrderID(rs.getInt(1));
		    		 order.setUsername1(rs.getString(2));
		    		 order.setUsername2(rs.getString(3));
		    		 order.setGoodsID1(rs.getString(4));
		    		 order.setGoodsID2(rs.getString(5));
		    		 order.setTime(rs.getDate(6));
		    		 
		    	 }
		    	 rs.close();
		    	 pstmt.close();
		    	
		    }catch (Exception e) {
				// TODO: handle exception
		    	throw new Exception("���������쳣") ;
		    }
		    	finally{  
		            // �ر����ݿ�����  
		            dbc.close() ;  
		         
			}
		
		
		return null;
	}

	@Override
	public List<order> queryByname(String name) throws Exception {
		// TODO Auto-generated method stub
		String sql="call userorder(?)";
		 DataBaseConnection dbc=null;
		 List<order> list=new ArrayList<order>();
		    PreparedStatement pstmt=null;
		    try 
		    {
		    	 dbc=new DataBaseConnection();
		    	 pstmt = dbc.getConnection().prepareStatement(sql) ; 
		    	 pstmt.setString(1, name);
		    	
		    	 ResultSet rs=pstmt.executeQuery();
		    	 while(rs.next())
		    	 {
		    		 order order=new order();
		    		 order.setOrderID(rs.getInt(1));
		    		 order.setUsername1(rs.getString(2));
		    		 order.setUsername2(rs.getString(3));
		    		 order.setGoodsID1(rs.getString(4));
		    		 order.setGoodsID2(rs.getString(5));
		    		 order.setTime(rs.getDate(6));
		    		 
		    	 }
		    	 rs.close();
		    	 pstmt.close();
		    	
		    }catch (Exception e) {
				// TODO: handle exception
		    	throw new Exception("���������쳣") ;
		    }
		    	finally{  
		            // �ر����ݿ�����  
		            dbc.close() ;  
		         
			}
		
		return list;
	}

}
