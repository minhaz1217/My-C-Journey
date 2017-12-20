#include<iostream>
using namespace std;
int main(){
    int a = 50, b=10,c=100;
    c = a>b?b=100:90;
    cout << b << endl;
    cout << c << endl;
    a>b?cout << "YES" : cout << "No";
	return 0;
}
