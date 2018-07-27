#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){

    long long int a,b;
    cin >> a >> b;
    while(b--){
        if(a%10 == 0){
            a = a/10;
        }else{
            a--;
        }
    }
    cout << a << endl;

    return 0;
}
