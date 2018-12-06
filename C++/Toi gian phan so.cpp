#include <iostream>
#include <cmath>
using namespace std;

struct Fraction
{
    int numerator, denominator; 
};
typedef struct Fraction Fraction;

void nhap(Fraction &frac)
{
	cout << "\nNhap tu: ";
	cin >> frac.numerator;
	
	cout << "\nNhap mau: ";
	cin >> frac.denominator;
}

void reduceFrac(Fraction &frac)
{
    for (int i = frac.numerator; i > 1; i--)
    {
       	if ((frac.numerator % i == 0) && (frac.denominator % i == 0))
    	{
        	frac.numerator /= i;
        	frac.denominator /= i;
    	}
    }
    cout << "Phan so rut gon: " << frac.numerator << "/" << frac.denominator << endl;
}

int main()
{
	cout << "Chuong trinh rut gon phan so";
	Fraction frac;
	nhap(frac);
	reduceFrac(frac);
	return 0;
}
