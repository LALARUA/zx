#include "stdio.h"
#include "stdlib.h"
void getWord(FILE *fp,int *num_char,int *num_word){
    char ch;
    do{
        *num_char=*num_char+1;
        ch=fgetc(fp);
    }while((ch>='a'&&ch<'z')||(ch>='A'&&ch<='Z')||ch=='_');//直到这个位置不是一个字符
    *num_word=*num_word+1;
    fseek(fp,-1,SEEK_CUR);   //指向当前位置的前一个位置
}

int main(int argc, char* argv[])
{   
    FILE *fp;                            //创建一个文件
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
        else if(ch=='\n'){              //如果是\n 则行数加1
            num_line++;
        }
        else if(ch=='\0'||ch=='\t'){
            flag=1;
        }
        else
            num_char+=1;
    }
     rewind(fp);
    printf("字符数为:%d",num_char);
    printf("\n");
    printf("单词数为:%d",num_word);
    printf("\n");
    printf("行数为:%d",num_line);
	
	printf("\n输入你想统计的字符\n");
	char o;
	char i=0;   //统计次数
	scanf("%c",&o);
	while(!feof(fp)){      //遍历文件
        ch=fgetc(fp);      
        if(o==ch)          //如果相同则i加1
           i++;
	 }
	  printf("%c出现的次数为:%d",o,i); 
	  fclose(fp);
    printf("\n");
    return 0;

}