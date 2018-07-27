#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int a,b,c,n;
    cin >> a >> b >> c >> n;

    a = a-c;
    b = b-c;
    if( (a+b+c) < n && a>=0 && b >= 0 ){
        cout << n- (a+b+c) << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}
