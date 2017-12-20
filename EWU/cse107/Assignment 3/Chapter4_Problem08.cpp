#include<iostream>
using namespace std;
struct Fraction{
    int numerator, denominator;
};
int main(){
    Fraction f1,f2,f3;
    char extra;
    cout << "Enter first fraction(n/d): ";
    cin >> f1.numerator >> extra >> f1.denominator;
    cout << "Enter second fraction(n/d): ";
    cin >> f2.numerator >> extra >> f2.denominator;
    f3.numerator = (f1.numerator*f2.denominator) + (f1.denominator*f2.numerator);
    f3.denominator =  f1.denominator*f2.denominator;
    cout << "Sum = " << f3.numerator << "/" <<  f3.denominator  << endl;
	return 0;
}
