#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    int n,a,counter;
    string str;
    cin >> n;
    cin >> str;
    a = 0;
    counter = 1;
    while(a< n){
        cout << str[a];
        a += counter;
        counter++;
    }
    cout << endl;

    return 0;
}
