#include <iostream>
#include <cmath>
using namespace std;

struct Fraction
{
    int numerator, denominator; 
};
void nhap(Fraction& frac)
{
	cin>>frac.numerator;
	cin>>frac.denominator;
}
Fraction reduceFrac(Fraction& frac)
{
	int tu,mau;
	if(frac.denominator>frac.numerator)
	{
    	for(int i=frac.numerator; i>1; i--)
    	{
        	if((frac.numerator%i==0)&&(frac.denominator%i==0))
        	{
          		tu = frac.numerator / i;
            	mau  = frac.denominator /i;
            	break; 
        	}
 			      
    	}
    	 cout<<tu<<" "<<"/"<<" "<<mau;
    }
}
int main()
{
	Fraction frac;
	nhap(frac);
	reduceFrac(frac);
	return 0;
}
