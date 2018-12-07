#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){

    long long int a,b,c,d,e,f,ans;
    cin >> a >> b >> c;
    cin >> d >> e >> f;
    ans = 0;
    if(a<d){
        ans += (d-a);
    }
    if(b<e){
        ans += (e-b);
    }
    if(c < f){
        ans += (f-c);
    }

    cout << ans << endl;

    return 0;
}
