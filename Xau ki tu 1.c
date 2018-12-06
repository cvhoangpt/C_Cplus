/*
Vi?t chuong trình th?c hi?n các công vi?c sau:
a) Nh?p vào s? nguyên N (0 < N < 10).
b) Nh?p m?ng A có N so nguyên. In m?ng A ra màn hình.
c) Tính giá tr? m?ng S[i] theo công th?c:
_S[i]=T neu A[i] là so nguyên to
_S[i]=K neu A[i] là so nguyên duong không phai nguyên to?
_S[i]=A neu A[i] là các tru?ng h?p khác
Hi?n m?ng S ra màn hình
*/

#include <stdio.h>
#include <conio.h>

int main()
{
	int i,N;
	do
	{
		printf("Nhap vao so N: ");scanf("%d",&N);
		if (N<=0 && N>=10) printf("\nXin moi nhap lai... ");
	}
	while (N<=0 && N>=10);
	
	char A[N];
	for (i=0;i<N;i++) 
	{
		printf("Nhap A[%d]: ",i);scanf("%s",A[i]);
	}
	printf("Mang A co cac phan tu la:\n");
	for (int i=0;i<N;i++) printf(A[i]);
	
	for ()
	

