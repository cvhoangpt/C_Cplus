/*
Nhap tu ban phim mot so N, in ra man hinh so dao nguoc cua so do.
VD: Nhap vao 12345 in ra so dao nguoc la 54321
*/
#include <stdio.h>
#include <conio.h>

int main()
{
	int N,temp;
	
	printf("Nhap vao so N: ");scanf("%d",&N);
	printf("So dao nguoc cua N la ");
	while (N > 0)
	{
		temp = N % 10;
		printf("%d",temp);
		N /= 10;
	}
	getch();
	return 0;
}
	
			
