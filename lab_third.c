/*�ϲ��ļ��Ľṹ�ǵ�һ���������ݱ�ʾ��һ���ļ���
�ļ������ȣ����ŵ�˫�������ݱ�ʾ��һ���ļ����ݵ��ֽ���
Ȼ���Ǹ��ļ����ļ������ļ����ݣ������ǵڶ�������������
���һ�����������Ǻϲ����ļ�����*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 1024
char buffer[SIZE];
 FILE *fp1,*fp2;
double sizef,ev_sizef;
 
void menu123(); /*�������ѡ��˵�*/
void divide123();/*�ָ��ļ�*/
void unite123();/*�ϲ��ļ�*/
void unitefile123();/*�ϲ��ļ�*/
void dividefile(int );/*�ָ��ļ�*/
int sizefile(fp)/*�����ļ���С*/
FILE *fp;                             /*�����ļ�����ָ��*/
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
void menu123()            /*�������ѡ��˵�*/
{
    int n;
    do
     {
         printf("   +      ��ѡ����Ҫ������ļ�ѡ� +\n");
         printf("   + 1.�����ļ�  2.�ϲ��ļ�  3.�˳�  +\n");
         printf("   ����������ѡ��:");
         scanf("%d",&n);
         if(n==1)
		 divide123();/*�ָ��ļ�*/
         else
         if(n==2)
         unite123();/*�ϲ��ļ�*/
         else
         if(n==3)
         exit(0);/*�˳�*/
     }while(n<1||n>3);
}
void unite123()              /*�ϲ��ļ�*/
{
  int n;
  char name[25],c;
  lp:
  lp1:
  printf(" \n\n�������źϲ��ļ������ļ���·��Ϊ:");
  scanf("%s",name);
  if((fp1=fopen(name,"wb"))==NULL)
    {
     printf("\n·������,�Ƿ���������(Y/N):");
     getchar();
     c=getchar();
     if(c=='Y'||c=='y')
     goto lp1;
     else
     menu123();
     }
  unitefile123();
  printf("\n�ϲ��ļ��ɹ�,�Ƿ�����ϲ������ļ�(Y/N):");
  getchar();
  c=getchar();
  if(c=='Y'||c=='y')
  goto lp;
  else
  menu123();
}
void unitefile123()      /*�ϲ��ļ�*/
{
  int i=1;
  char name[25],c;
  do
    {
     lp1:
     printf("\n��������Ҫ�ϲ��ĵ�%d���ļ���·��:",i++);
     scanf("%s",name);
      if((fp2=fopen(name,"rb+"))==NULL)
      {
        printf("\n������ļ�·������,�Ƿ����������ļ���λ��(Y/N):");
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
      printf("\n�Ƿ�������кϲ�(Y/���������): ");
      getchar();
      c=getchar();
    }while(c=='y'||c=='Y');
    fprintf(fp1,"% d",i);
  fclose(fp1);
}
void divide123()     /*�ָ��ļ�*/
{
  int n;
  char name[25],c;
  lp:
  lp1:
  printf("\n�������������ļ���·��:");
  scanf("%s",name);
  if((fp2=fopen(name,"rb"))==NULL)
    {
     printf("\n�ļ�·������,�Ƿ���������(Y/N):");
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
/*  printf("\n��Ҫ�����ļ��ָ�Ϊ����:");
  lp2:
  scanf("%d",&n);
  if(n<1)
  { printf("\n��Ǹ,��������ȷ�ķָ����:"); goto lp2;}
  else
 sizef=sizefile(fp2);
   ev_sizef=sizef/n;                      //���ָ��ÿһ�����ļ��Ĵ�С
  printf("\n���ļ�����Ϊ��%.0f�ֽ�,�ָÿ���ļ���СΪ:%.0f �ֽ�\n",sizef,ev_sizef);*/
  dividefile(n);//�ָ����
  printf("\n�ָ�ɹ�,�Ƿ�������зָ�(Y/N)\n");
  getchar();
  c=getchar();
  printf("\n\n");
  if(c=='Y'||c=='y')
  goto lp;
  else
   menu123();
}
void dividefile(int n)      //�ָ��ļ�
{
  int i,d=1;
  int sizename;
  double sizetext;
  char name[25],*c;
  c=(char*)malloc(sizeof(char));
  for(i=0;i<n;i++)
   {
     lp1:
 //    printf("\n��������Ҫ�ָ��%d�����ļ���λ��:",i+1);
     fscanf(fp2,"%d",sizename);
     fscanf(fp2,"%ld",sizetext);
     fread(name,sizename,1,fp2);
      if((fp1=fopen(name,"wb"))==NULL)
      {
        printf("\n��������ļ�·������, �Ƿ����������ļ�·��(Y/N):");
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
        while(fread(c,1,1,fp2))//cָ���ڴ��ָ��,
        {
          fwrite(c,1,1,fp1);
        }
     fclose(fp1);
    }
    free(c);
    fclose(fp2);
}

