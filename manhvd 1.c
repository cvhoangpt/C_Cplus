#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
	char **Ten = (char **)malloc(100* sizeof(char *));
	
	int i;
	for (i = 0; i < 5; i++)
		*(Ten+i) = (char *)malloc(100* sizeof(char));//**Ten = *(Ten+i)
	//*(Ten+i)=(char *)realloc(Ten,50* sizeof(char));
	
	**Ten = {'Manh','Thuyen'};//khai bao phan tu char dung '' chu ko dung " "
	//Ten duoc khai bao la kieu ki tu, no se ko hieu xau ki tu
	// Loi { chua hieu nguyen nhan
	// **Ten ko the tu gian ra de chua mot luc 2 phan tu, va chua nhung ki tu tiep theo
	getch();
	return 0;
}
