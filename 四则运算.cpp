#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include <windows.h>
void Shengcheng(int gr);
int Simple(int l);
int real(int l);
int MaxGYS(int a,int b);
int system(const char *string);

int main(void)
{
	int n;
	int gr=0;//记录分数
	
Loop1: printf("\n\n\n\n\t\t\t[1] 生成小学数学四则运算30题练习\n\n\t\t\t[2] 退出程序\n\n\t\t\t请输入相应的选项,按回车键确定:");
	   scanf("%d",&n);
	   system("cls");
	   if (n==1)
		   Shengcheng(gr);
	   else
		   if (n==2)
		   {
			   
			   return 0;
		   }
		   else 
			   printf("输入错误请重新输入");
		   goto Loop1;
		   return 0;
}

void Shengcheng(int gr)
{   
	int l;
    printf("分号用空格代替\n");

	int m,i;
	for(i=0;i<30;i++)
	{
		m=rand()%2+1;
		if (m==1)
			l=Simple(gr);
		else
			l=real(gr);
	} 
	printf("总得分为%d",l);
	system("pause");
	system("cls");
	system("pause");
	system("cls");
	return ;
}

int Simple(int l)
{
	int m,b,c,d,t,p;//m为运算符 b,c为操作数 d为正确答案 p为回答
	m=rand()%3+1;
	b=rand()%20+1;
	c=rand()%20+1;
	switch(m)
	{
	case 1:
		d=b+c;
		printf("%d+%d=",b,c);
		scanf("%d",&p);
		printf("正确答案为%d",d);
		if(p==d)
		{printf("回答正确\n");
		l++;}
		else printf("回答错误\n");
       break;
	case 2:{
		if(b>c)
		{
			t=b;
			b=c;
			c=t;
		}
		d=b-c;
		printf("%d-%d=",b,c);
       scanf("%d",&p);
		{printf("回答正确\n");
		l++;}
		if(p==d)
		{printf("回答正确\n");
		l++;}
		else printf("回答错误\n");
		   }break;
	case 3:{
		d=b*c;
		m= rand()%2+1;
		if(m==1)
			printf("%d*%d=",b,c);
         scanf("%d",&p);
		printf("正确答案为%d",d);
		if(p==d)
		{printf("回答正确\n");
		l++;}
		else printf("回答错误\n");
		
			printf("%d/%d=",d,b);
		scanf("%d",&p);
		printf("正确答案为%d",d);
		if(p==c)
		{printf("回答正确\n");
		l++;}
		else printf("回答错误\n");
		   } break;
	}
	return l;
	
}



int real(int l)
{
	int a,b,c,d,e,f,g,h,t;
	int y,u;//输入的答案
	a=rand()%4+1;
	b=rand()%9+1;//第一个数字分子
	c=rand()%9+1;//第一个数字分母
	d=rand()%9+1;//第二个数字分子
	e=rand()%9+1;//第二个数字分母
	if(b>c)
	{
		t=b;
		b=c;
		c=t;
	}
	if(d>e)
	{
		t=d;
		d=e;
		e=t;
	}
	
	switch(a)
	{
	case 1:{
		f=c*e;
		g=b*e+d*c;
		h=MaxGYS(g,f);
		f=f/h;
		g=g/h;
		printf("(%d/%d)+(%d/%d)=",b,c,d,e);
		scanf("%d",&y);
		scanf("%d",&u);
		printf("正确答案为%d/%d",g,f);
		if(y==g&&u==f)
		{printf("回答正确\n");
		l++;}
		else printf("回答错误\n");
		   }break;
	case 2:{
		f=c*e;
		g=b*e-d*c;
		if(g>0)
		{
			h=MaxGYS(g,f);
			f=f/h;
			g=g/h;
		printf("(%d/%d)-(%d/%d)=",b,c,d,e);
		scanf("%d",&y);
		scanf("%d",&u);
		printf("正确答案为%d/%d",g,f);
		if(y==g&&u==f)
		{printf("回答正确\n");
		l++;}
		else printf("回答错误\n");
		}
		else
		{
			g=abs(g);
			h=MaxGYS(g,f);
			f=f/h;
			g=g/h;
			printf("(%d/%d)-(%d/%d)=",b,c,d,e);
		scanf("%d",&y);
		scanf("%d",&u);
		printf("正确答案为%d/%d",g,f);
		if(y==g&&u==f)
			printf("回答正确\n");
		else printf("回答错误\n");
		}
		   }break;
	case 3:{
		f=c*e;
		g=b*d;
		h=MaxGYS(g,f);
		f=f/h;
		g=g/h;
		printf("(%d/%d)*(%d/%d)=",b,c,d,e);
		scanf("%d",&y);
		scanf("%d",&u);
		printf("正确答案为%d/%d",g,f);
		if(y==g&&u==f)
		{printf("回答正确\n");
		l++;}
		else printf("回答错误\n");
		   }break;
	case 4:{ 
		f=b*e;
		g=c*d;
		h=MaxGYS(g,f);
		f=f/h;
		g=g/h;
		printf("(%d/%d)/(%d/%d)=",b,c,d,e);
		scanf("%d",&y);
		scanf("%d",&u);
		printf("正确答案为%d/%d",g,f);
		if(y==g&&u==f)
		{printf("回答正确\n");
		l++;}
		else printf("回答错误\n");
		   }
	default:break;
	}
	return l;
}


int MaxGYS(int a,int b)//计算最大公约数
{
	int c,t;
	if(a<b)
	{
		t=a;
		a=b;
		b=t;
	}
	while(b!=0)
	{
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}