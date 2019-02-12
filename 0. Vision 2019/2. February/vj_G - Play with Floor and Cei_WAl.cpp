#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int main(){
    double tc,x,a,b,q,p,k;
    cin >> tc;
    while(tc--){
        cin >> x >> k;
        a = floor(x/k);
        b = ceil(x/k);
        if(a == b){
            cout << 0 << " " << x/a << endl;
            continue;
        }
        q = (x - (a*k))/ (b-a);
        p = k -q;
        cout << p << " " << q << endl;
    }


    return 0;
}
