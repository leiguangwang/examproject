/*合并文件的结构是第一个整型数据表示第一个文件的
文件名长度，接着的双精度数据表示第一个文件内容的字节数
然后是该文件的文件名和文件内容，依次是第二、三····
最后一个整型数据是合并的文件个数*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 1024
char buffer[SIZE];
 FILE *fp1,*fp2;
double sizef,ev_sizef;
 
void menu123(); /*主界面的选择菜单*/
void divide123();/*分割文件*/
void unite123();/*合并文件*/
void unitefile123();/*合并文件*/
void dividefile(int );/*分割文件*/
int sizefile(fp)/*计算文件大小*/
FILE *fp;                             /*定义文件类型指针*/
{
    sizef=0;
    while(!feof(fp))
    { fgetc(fp);
        sizef++;    }
    rewind(fp);
    return sizef-1;
} 
int main()
{
    menu123();
}
void menu123()            /*主界面的选择菜单*/
{
    int n;
    do
     {
         printf("   +      请选择需要处理的文件选项： +\n");
         printf("   + 1.分离文件  2.合并文件  3.退出  +\n");
         printf("   请输入以上选项:");
         scanf("%d",&n);
         if(n==1)
		 divide123();/*分割文件*/
         else
         if(n==2)
         unite123();/*合并文件*/
         else
         if(n==3)
         exit(0);/*退出*/
     }while(n<1||n>3);
}
void unite123()              /*合并文件*/
{
  int n;
  char name[25],c;
  lp:
  lp1:
  printf(" \n\n请输入存放合并文件的新文件的路径为:");
  scanf("%s",name);
  if((fp1=fopen(name,"wb"))==NULL)
    {
     printf("\n路径错误,是否重新输入(Y/N):");
     getchar();
     c=getchar();
     if(c=='Y'||c=='y')
     goto lp1;
     else
     menu123();
     }
  unitefile123();
  printf("\n合并文件成功,是否继续合并其他文件(Y/N):");
  getchar();
  c=getchar();
  if(c=='Y'||c=='y')
  goto lp;
  else
  menu123();
}
void unitefile123()      /*合并文件*/
{
  int i=1;
  char name[25],c;
  do
    {
     lp1:
     printf("\n请输入想要合并的第%d个文件的路径:",i++);
     scanf("%s",name);
      if((fp2=fopen(name,"rb+"))==NULL)
      {
        printf("\n输入的文件路径有误,是否重新输入文件的位置(Y/N):");
        if(getchar()=='Y'||getchar()=='y')
          goto lp1;
        else
           menu123();
      }
        fprintf(fp1,"%d ",strlen(name));
        fprintf(fp1,"%ld ",sizefile(fp2));
        fputs(name,fp1);
		fprintf(fp1,"%c",'\n'); 
        while(fread(buffer,1,1,fp2))
            fwrite(buffer,1,1,fp1);
      fclose(fp2);
      printf("\n是否继续进行合并(Y/按下任意键): ");
      getchar();
      c=getchar();
    }while(c=='y'||c=='Y');
    fprintf(fp1,"% d",i);
  fclose(fp1);
}
void divide123()     /*分割文件*/
{
  int n;
  char name[25],c;
  lp:
  lp1:
  printf("\n请输入待分离的文件的路径:");
  scanf("%s",name);
  if((fp2=fopen(name,"rb"))==NULL)
    {
     printf("\n文件路径错误,是否重新输入(Y/N):");
     getchar();
     c=getchar();
     if(c=='Y'||c=='y')
        goto lp1;
     else
        menu123();
     }
   fseek(fp2,0L,2);
   fscanf(fp2,"%d",&n);
   rewind(fp2);
/*  printf("\n需要将·文件分割为几份:");
  lp2:
  scanf("%d",&n);
  if(n<1)
  { printf("\n抱歉,请输入正确的分割份数:"); goto lp2;}
  else
 sizef=sizefile(fp2);
   ev_sizef=sizef/n;                      //被分割后每一个子文件的大小
  printf("\n该文件长度为：%.0f字节,分割到每分文件大小为:%.0f 字节\n",sizef,ev_sizef);*/
  dividefile(n);//分割存盘
  printf("\n分割成功,是否继续进行分割(Y/N)\n");
  getchar();
  c=getchar();
  printf("\n\n");
  if(c=='Y'||c=='y')
  goto lp;
  else
   menu123();
}
void dividefile(int n)      //分割文件
{
  int i,d=1;
  int sizename;
  double sizetext;
  char name[25],*c;
  c=(char*)malloc(sizeof(char));
  for(i=0;i<n;i++)
   {
     lp1:
 //    printf("\n请输入需要分割第%d份新文件的位置:",i+1);
     fscanf(fp2,"%d",sizename);
     fscanf(fp2,"%ld",sizetext);
     fread(name,sizename,1,fp2);
      if((fp1=fopen(name,"wb"))==NULL)
      {
        printf("\n你输入的文件路径错误, 是否重新输入文件路径(Y/N):");
            if(getchar()=='Y'||getchar()=='y')
          goto lp1;
          else
          {
            fclose(fp2);
            menu123();
          }
       }
       d=1;
     if(i!=n)
        while(d<=sizetext)
       { fputc(fgetc(fp2),fp1); d++;}
      else
        while(fread(c,1,1,fp2))//c指向内存的指针,
        {
          fwrite(c,1,1,fp1);
        }
     fclose(fp1);
    }
    free(c);
    fclose(fp2);
}

