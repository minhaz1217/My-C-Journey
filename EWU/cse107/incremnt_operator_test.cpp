#include<iostream>
using namespace std;
int main(){
    int a = 2, b=5;
    cout << "Addition increment: " << b + ++a << endl;
    cout << "Sub increment: " << a << endl;
    for(a=0;a<b;a++){
        cout << a << endl;
    }
    cout << a << endl;
	return 0;
}
