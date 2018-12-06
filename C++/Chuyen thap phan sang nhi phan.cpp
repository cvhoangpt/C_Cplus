#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n,m;
	cout<<"so thap phan : ";
	cin>>n;
	int i=0, a[100];
	while (n!=0)
	{
		a[i] = n%2 ;
		n = n / 2 ;
		m = i;
		i++;
	}
	cout<<"chuyen sang nhi phan ta duoc : ";
	for(int i = m; i>=0; i--)
	{
		cout<<a[i];
	}
}
