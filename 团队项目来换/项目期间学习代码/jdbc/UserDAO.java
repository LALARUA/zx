package ������;
import java.util.* ; 


	public interface UserDAO{  
	    // ���Ӳ���  
	    public void insert(User user) throws Exception ;  
	    // �޸Ĳ���  
	    public void update(User user) throws Exception ;  
	    // ɾ������  
	    public void delete(int userid) throws Exception ;  
	    // ��ID��ѯ����  
	    public User queryById(int userid) throws Exception ;  
	    // ��ѯȫ��  
	    public List queryAll() throws Exception ;  
	    


}
