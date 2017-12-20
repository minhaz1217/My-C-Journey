//find the power of 2 using bitwise operations
//return a<<(n-1);
#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int a,p;
    a = 2;
    p = 5;
    cout << (a<<(p-1)) << endl;

    return 0;
}
