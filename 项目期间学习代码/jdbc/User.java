package 来换网;

public class User {
private int Userid;     //用户ID
private String username;//用户名
private String userpassword; //用户密码

private String phone;   //手机号码
private String sex;//性别
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
