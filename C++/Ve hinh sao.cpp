#include<iostream>
using namespace std;
int main() 
{
	int n;
	cout << "\nNhap so dong n : ";
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= n; j++) 
		{
			if (j <= i - 1) cout << " ";
			else cout << "*";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}