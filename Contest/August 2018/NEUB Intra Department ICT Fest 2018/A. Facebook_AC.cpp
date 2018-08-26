#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    long long tc,caseCounter = 1;
    cin >> tc;
    while(tc--){
        double h,m,tt,a;
        char c;
        cin >> h >> c >> m;
        tt = h*60 + m;
        a = tt - 2250;
        if((int)a%30 == 0 && a >=0){
            m = a/30;
            cout << "Case " << caseCounter++ << ": " << floor(m/60.0) << ":" << ((int)m)%60<< endl;

        }else{
            cout << "Case " << caseCounter++ << ": NOT POSSIBLE" << endl;
        }
    }

    return 0;
}
