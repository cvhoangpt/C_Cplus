/*
Dùng mang các xâu. Khai báo char dslop[10][30]; 
Không dùng c?u trúc (structure). 
L?p chuong trình th?c hi?n các công vi?c sau:
1. Nh?p vào danh sách tên các h?c sinh c?a m?t l?p v?i s? h?c sinh n <= 10 nh?p t? bàn phím.
2. S?p x?p danh sách theo th? t? ABC.
3. Ðua danh sách ra màn hình.
*/
#include<stdio.h>
#include<conio.h>
#include<string.h>

int main()
{
	char dslop[10][30],temp[30];
	int n,i,j;
	do
		{
		printf("Nhap so hoc sinh toi da 10 nguoi: ");scanf("%d",&n);
		if (n<0 || n>10) printf("Xin moi nhap lai: ");
		}
	while (n<0 || n>10);
	
	printf("Nhap ten cac hoc sinh: \n");
	for (i = 0;i < n; i++)
		{
			printf("Nhap ten ban thu %d:\n",i+1);
			scanf("%s",&dslop[i]);
		}
	for (i = 1; i < n; i++) 
    	for (j = 1; j < n; j++)
         	if (strcmp(dslop[j - 1], dslop[j]) > 0) 
			{
            	strcpy(temp, dslop[j - 1]);
            	strcpy(dslop[j - 1], dslop[j]);
            	strcpy(dslop[j], temp);
         	}
    printf("\nSap xep theo abc: ");
   	for (i = 0; i < n; i++) printf("\n%s", dslop[i]);
	getch();
	return 0;
}
