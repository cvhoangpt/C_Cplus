#include <stdio.h>
int f(int k, int n)
{
	if(k==0 || n==0) return 1;
	if(k>n) return 3 + f(k-n,n);
	else return 5+f(k,n-k);
}
int main(int argc,char** argv)
{
	printf("%d\n",f(8,5));
}
