#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    int x;
    cin >> x;
    for(int a = 1;a<= x;a++){
        for(int b =1;b<=x;b++){
            if( (a%b == 0) && (a*b > x) && (a/b < x) ){
                cout << a << " " << b << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;

    return 0;
}
