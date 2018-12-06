#include <stdio.h>
#include <conio.h>


// de quy

int uoclemax1(int n, int k)
{
	if (n == 1)
		return 1;

	if (n% k == 0 && k %2 != 0)
		return k;

	return uoclemax1(n, k - 1);
}

// Khu de quy

int uoclemax2 ( int n)
{
	int k;
	for ( k = n ; k >= 1; k--)
	{
		if (n % k == 0 && k % 2 != 0)
				return k;
	}
}

// de quy cach 2

int DeQuy(int n)
{
	if (n % 2 != 0)
		return n;

	return DeQuy(n / 2);
}

int main()
{
	int n;

	printf("Nhap n = ");
	scanf_s("%d", &n);

	printf("Uoc le lon nhat cua %d la %d \n", n, uoclemax1(n, n));

	printf("Uoc le lon nhat cua %d la %d \n", n, uoclemax2(n));

	printf("Uoc le lon nhat cua %d la %d \n", n, DeQuy(n));

	_getch();

	return 0;
}
