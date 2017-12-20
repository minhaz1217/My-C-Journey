#include<iostream>
using namespace std;
int main(){
    int a,b,c,d,sum1,sum2;
    char extra;
    cout << "Enter first fraction: ";
    cin >> a >> extra >> b;
    cout << "Enter second fraction: ";
    cin >> c >> extra >> d;
    sum1 = (a*d) + (b*c);
    sum2 =  b*d;
    cout << "Sum = " << sum1 << "/" << sum2 << endl;
	return 0;
}
