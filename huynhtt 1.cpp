#include<stdio.h>
#include<conio.h>

int main()
{
	
	int A[1000];
	int sophantu;
	printf("Nhap so phan tu cua mang: ");scanf("%d",&sophantu);
	for (int i=0;i < sophantu;i++) 
	{
		printf("A[%d]",i+1);scanf("%d",&A[i]);
	}
	int max=-99999,s=0;
	for (int i=0;i < sophantu;i++)
	{
		for (int j=i;j < sophantu; j++ )
		{
			for(int k = i; k < j; k++)
			{
				s += A[k];
			}
			if (s > max) max = s;
			s = 0;
		}	
	}
	printf("Tong la: %d",max);
}
