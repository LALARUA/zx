package ������;

public class User {
private int Userid;     //�û�ID
private String username;//�û���
private String userpassword; //�û�����

private String phone;   //�ֻ�����
private String sex;//�Ա�
public int getUserid() {
	return Userid;
}
public void setUserid(int userid) {
	Userid = userid;
}
public String getUsername() {
	return username;
}
public void setUsername(String username) {
	this.username = username;
}
public String getUserpassword() {
	return userpassword;
}
public void setUserpassword(String userpassword) {
	this.userpassword = userpassword;
}
public String getPhone() {
	return phone;
}
public void setPhone(String phone) {
	this.phone = phone;
}
public String getSex() {
	return sex;
}
public void setSex(String sex) {
	this.sex = sex;
}

}
