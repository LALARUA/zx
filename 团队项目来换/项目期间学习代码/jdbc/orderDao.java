package ������;

import java.util.List;

public interface orderDao {
	//�������
	public void insert(order order) throws Exception ;  
    
	 
   
    // ��ID��ѯ����  
    public List<order> queryByname(String name) throws Exception ;  
    // ��ѯȫ��  
    public List<order> queryAll() throws Exception ;  
}
