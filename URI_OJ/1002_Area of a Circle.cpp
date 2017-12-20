#include<iostream>
#include<iomanip>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    double a;
    cin >> a;
    cout << fixed << setprecision(4)<< "A="<<a*a*3.14159 << endl;
	return 0;
}
