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
	int gr=0;//��¼����
	
Loop1: printf("\n\n\n\n\t\t\t[1] ����Сѧ��ѧ��������30����ϰ\n\n\t\t\t[2] �˳�����\n\n\t\t\t��������Ӧ��ѡ��,���س���ȷ��:");
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
			   printf("�����������������");
		   goto Loop1;
		   return 0;
}

void Shengcheng(int gr)
{   
	int l;
    printf("�ֺ��ÿո����\n");

	int m,i;
	for(i=0;i<30;i++)
	{
		m=rand()%2+1;
		if (m==1)
			l=Simple(gr);
		else
			l=real(gr);
	} 
	printf("�ܵ÷�Ϊ%d",l);
	system("pause");
	system("cls");
	system("pause");
	system("cls");
	return ;
}

int Simple(int l)
{
	int m,b,c,d,t,p;//mΪ����� b,cΪ������ dΪ��ȷ�� pΪ�ش�
	m=rand()%3+1;
	b=rand()%20+1;
	c=rand()%20+1;
	switch(m)
	{
	case 1:
		d=b+c;
		printf("%d+%d=",b,c);
		scanf("%d",&p);
		printf("��ȷ��Ϊ%d",d);
		if(p==d)
		{printf("�ش���ȷ\n");
		l++;}
		else printf("�ش����\n");
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
		{printf("�ش���ȷ\n");
		l++;}
		if(p==d)
		{printf("�ش���ȷ\n");
		l++;}
		else printf("�ش����\n");
		   }break;
	case 3:{
		d=b*c;
		m= rand()%2+1;
		if(m==1)
			printf("%d*%d=",b,c);
         scanf("%d",&p);
		printf("��ȷ��Ϊ%d",d);
		if(p==d)
		{printf("�ش���ȷ\n");
		l++;}
		else printf("�ش����\n");
		
			printf("%d/%d=",d,b);
		scanf("%d",&p);
		printf("��ȷ��Ϊ%d",d);
		if(p==c)
		{printf("�ش���ȷ\n");
		l++;}
		else printf("�ش����\n");
		   } break;
	}
	return l;
	
}



int real(int l)
{
	int a,b,c,d,e,f,g,h,t;
	int y,u;//����Ĵ�
	a=rand()%4+1;
	b=rand()%9+1;//��һ�����ַ���
	c=rand()%9+1;//��һ�����ַ�ĸ
	d=rand()%9+1;//�ڶ������ַ���
	e=rand()%9+1;//�ڶ������ַ�ĸ
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
		printf("��ȷ��Ϊ%d/%d",g,f);
		if(y==g&&u==f)
		{printf("�ش���ȷ\n");
		l++;}
		else printf("�ش����\n");
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
		printf("��ȷ��Ϊ%d/%d",g,f);
		if(y==g&&u==f)
		{printf("�ش���ȷ\n");
		l++;}
		else printf("�ش����\n");
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
		printf("��ȷ��Ϊ%d/%d",g,f);
		if(y==g&&u==f)
			printf("�ش���ȷ\n");
		else printf("�ش����\n");
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
		printf("��ȷ��Ϊ%d/%d",g,f);
		if(y==g&&u==f)
		{printf("�ش���ȷ\n");
		l++;}
		else printf("�ش����\n");
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
		printf("��ȷ��Ϊ%d/%d",g,f);
		if(y==g&&u==f)
		{printf("�ش���ȷ\n");
		l++;}
		else printf("�ش����\n");
		   }
	default:break;
	}
	return l;
}


int MaxGYS(int a,int b)//�������Լ��
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