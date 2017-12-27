package 来换网;

import java.util.List;

public interface orderDao {
	//插入操作
	public void insert(order order) throws Exception ;  
    
	 
   
    // 按ID查询操作  
    public List<order> queryByname(String name) throws Exception ;  
    // 查询全部  
    public List<order> queryAll() throws Exception ;  
}
