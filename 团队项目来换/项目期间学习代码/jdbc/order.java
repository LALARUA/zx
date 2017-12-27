package À´»»Íø;

import java.util.Date;

public class order {
    private int orderID;
	private String username1;
    private String username2;
    private String goodsID1;
    private String goodsID2;
    private Date time;
	public int getOrderID() {
		return orderID;
	}
	public void setOrderID(int orderID) {
		this.orderID = orderID;
	}
	public String getUsername1() {
		return username1;
	}
	public void setUsername1(String username1) {
		this.username1 = username1;
	}
	public String getUsername2() {
		return username2;
	}
	public void setUsername2(String username2) {
		this.username2 = username2;
	}
	public String getGoodsID1() {
		return goodsID1;
	}
	public void setGoodsID1(String goodsID1) {
		this.goodsID1 = goodsID1;
	}
	public String getGoodsID2() {
		return goodsID2;
	}
	public void setGoodsID2(String goodsID2) {
		this.goodsID2 = goodsID2;
	}
	public Date getTime() {
		return time;
	}
	public void setTime(Date time) {
		this.time = time;
	}
    
}
