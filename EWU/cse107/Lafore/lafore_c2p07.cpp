#include<iostream>
using namespace std;
int main(){
    double c, f;
    cout << "Enter celsius: ";
    cin >> c;
    f = c*9/5 + 32;
    cout << "The Celsius in fahrenheit is: " << f;
	return 0;
}
