/*
Vi?t chuong tr�nh th?c hi?n c�c c�ng vi?c sau:
a) Nh?p v�o s? nguy�n N (0 < N < 10).
b) Nh?p m?ng A c� N so nguy�n. In m?ng A ra m�n h�nh.
c) T�nh gi� tr? m?ng S[i] theo c�ng th?c:
_S[i]=T neu A[i] l� so nguy�n to
_S[i]=K neu A[i] l� so nguy�n duong kh�ng phai nguy�n to?
_S[i]=A neu A[i] l� c�c tru?ng h?p kh�c
Hi?n m?ng S ra m�n h�nh
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
	

