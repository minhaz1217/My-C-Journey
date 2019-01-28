#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    long long int tc,a,b,c,d;
    cin >> tc;
    while(tc--){
        cin >> a >> b >> c >>d;
        cout << a;
        if(c != a){
            cout << " " << c;
        }else{
            cout << " " << d;
        }
        cout << endl;
    }
    return 0;
}
