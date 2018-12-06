#include <stdio.h>

int main ()
{
	int i, n, count1=0, count2=0, temp;
	printf("Nhap n: ");scanf("%d",&n);
	
	for(i = 0;i < n;i++)
	{
	    printf("Nhap khoi luong qua thu %d: ",i+1);scanf("%d",&temp);
		if(temp == 100) count1++;
	    else count2++;
	}
	
	if(count1 > 0)
	{
	    if(count1 % 2 == 0) printf("YES");
	    else printf("NO");
	}
	else if(count2 % 2 == 0) printf("YES");
	else printf("NO");
	
	return 0;
}
