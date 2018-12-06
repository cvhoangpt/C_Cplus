#include<stdio.h>
#include<conio.h>

int main()
{
	float n;
	float GiaTien;
	do
	{
		printf("\nNhap vao so km di duoc (0<=so km<=200): ");
		scanf("%f",&n);
		if(n<0||n>200) 
		{
			system("cls");
			printf("\nKhong hop le moi nhap lai !");
		}
	}
	while(n<0||n>200);
	
	if(n<=1)
	{
		GiaTien=15000;
	}
	else if(n>1&&n<=5)
	{
		GiaTien=15000+(n-1)*13500;
	}
	else
	{
		if(n<=120){
		GiaTien=15000+13500*4+11000*(n-5);
		}
		else
		GiaTien=(15000+13500*4+11000*(n-5))*0.9;
	}
	printf("\nSo tien di taxi la: %.2f VND",GiaTien);
	getch();
	return 0;			
}
