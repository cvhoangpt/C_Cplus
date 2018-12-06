/*TIM KIEM TUAN TU*/
int find(int a[],int n, int x)
{
	int i,k=-1;
	while (i<n) && (a[i] != x) i++;
	if (i==n) return -1
	else return i;
}


/*TIM KIEM NHI PHAN*/
int timkiem(int A[],int length,int x)
{
	int first=0,last=length-1;
	while (first <= last)
	{
		int mid = (first + last)/2;
		if (x > A[mid]) first = mid + 1;
		else if (x < A[mid]) last = mid -1;
		else 
		{
			printf("So %d tai vi tri %d",x,mid);
			return mid;
		}
	}
	printf("Khong ton tai %d trong mang",x);
	return -1;
}


