#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    string hello = "HELLO WORLD";
    hello.append(1, 'h');
    cout << hello << endl;
	return 0;
}
