#include <stdio.h>

int main()
{
	int thuaSo1, thuaSo2;
	printf("Nhap thuaSo1: ");scanf("%d",&thuaSo1);
	printf("Nhap thuaSo2: ");scanf("%d",&thuaSo2);
	
	printf("   %d\n",thuaSo1);
	printf("x");printf("   %d",thuaSo2);
	printf("______");
	printf("%d",thuaSo2 % 100);
	
	return 0;
}
