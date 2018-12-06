#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int n=0,m=20;
char **ds,*tg,ht[60];
void bosung();
void sapxep();
void indanhsach();
int main(){
char ch;
ds=new char *[m];
while(1)
{
	system("cls");
	printf("\n CHUONG TRINH QUAN LY SINH VIEN:");
	printf("\n 1. bo sung danh sach");
	printf("\n 2.sap xep danh sach theo ABC");
	printf("\n 3.indanh sach");
	printf("\n nhap tuwf 1 den 3 de chon, an phim bat ki de ket thuc");
	getch();
	fflush(stdin);
	ch=getch();
	if( ch=='1')
	bosung();
	else if(ch=='2')
	sapxep();
	else if(ch=='3')
	indanhsach();
	else
	{
		fflush(stdin);
		printf(" chan roi a??y/..");
		if( ch=='y'||ch=='Y') break;
	}
}
}
void bosung()
{int i;
char **ds2;
	while (1)
	{
		printf("\n nhap sinh vien thu %d",n+1);
		fflush(stdin);
		gets(ht);
		if (ht[0]=='\0') break;
		i=strlen(ht)+1;
		ds[n]=new char[i];
		strcpy (ds[n],ht);
 
		n++;
		if(n>m)
		{
			m+=20;
			ds2=new char *[m];
			for(i=0;i<n;i++)
			ds2[i]=ds[i];
			delete[]ds;
			ds=ds2;
		}
	}
}
void sapxep()
{
	int i,j;
	for (i=0;i<n+1;i++)
	for (j=i+1;j<n;j++)
 
		if( strcmp(ds[i],ds[j])>0)
		{
			tg=ds[i];//neu ko dung con tro strcpy(tg,ds[i]);
			ds[i]=ds[j];
			ds[j]=tg;// hoan vi cac dia chi cac phan tu.ko can dung strcpy
		}
		printf("\n da sap xep xong!");
		getch();
	}
void indanhsach(){
	int i;
	printf("\n DANH SACH SINH VIEN");
	for(i=0;i<n;i++)
	puts(ds[i]);
	getch();
}
