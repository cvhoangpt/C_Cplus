#include <stdio.h>
#include <conio.h>

int main()
{
	int A[100];
	int N,i=0,temp1,temp2;
	printf("Chuong trinh chuyen doi SO THAP PHAN -> SO NHI PHAN (Z+)\n");
	printf("Nhap vao mot so thap phan (thuoc Z+): ");scanf("%d",&N);
	temp1=N;
	while (N >= 0)
	{
		A[i]=N%2;
		N/=2;
		temp2=i;
		i++;
		if (N==0) break;
	}
	printf("So nhi phan cua %d la ",temp1);
	while (temp2 >= 0)
	{
		printf("%d",A[temp2]);
		temp2--;
	}
	/*
	for (temp2;i<temp2;temp2--)
	{
	*/
	getch();
	return 0;
}
		
		
