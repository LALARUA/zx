#include "stdio.h"
#include "stdlib.h"
void getWord(FILE *fp,int *num_char,int *num_word){
    char ch;
    do{
        *num_char=*num_char+1;
        ch=fgetc(fp);
    }while((ch>='a'&&ch<'z')||(ch>='A'&&ch<='Z')||ch=='_');//ֱ�����λ�ò���һ���ַ�
    *num_word=*num_word+1;
    fseek(fp,-1,SEEK_CUR);   //ָ��ǰλ�õ�ǰһ��λ��
}

int main(int argc, char* argv[])
{   
    FILE *fp;                            //����һ���ļ�
    char ch;
    int num_word=0,num_line=0,num_char=0,flag;   
    fp=fopen("text.txt","a+");            
    if(fp==NULL){
        printf("the file open bit");
    }
    while(!feof(fp)){
        ch=fgetc(fp);
        if((ch>='a'&&ch<'z')||(ch>='A'&&ch<='Z')){
            getWord(fp,&num_char,&num_word);
        }
        else if(ch=='\n'){              //�����\n ��������1
            num_line++;
        }
        else if(ch=='\0'||ch=='\t'){
            flag=1;
        }
        else
            num_char+=1;
    }
     rewind(fp);
    printf("�ַ���Ϊ:%d",num_char);
    printf("\n");
    printf("������Ϊ:%d",num_word);
    printf("\n");
    printf("����Ϊ:%d",num_line);
	
	printf("\n��������ͳ�Ƶ��ַ�\n");
	char o;
	char i=0;   //ͳ�ƴ���
	scanf("%c",&o);
	while(!feof(fp)){      //�����ļ�
        ch=fgetc(fp);      
        if(o==ch)          //�����ͬ��i��1
           i++;
	 }
	  printf("%c���ֵĴ���Ϊ:%d",o,i); 
	  fclose(fp);
    printf("\n");
    return 0;

}