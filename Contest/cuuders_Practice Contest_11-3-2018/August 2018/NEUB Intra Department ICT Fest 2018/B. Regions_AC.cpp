#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    int tc,caseCounter =1;
    cin >> tc;
    while(tc--){
        long long int a,b;
        cin >> a >> b;
        a = abs(a-b);
        cout << "Case " << caseCounter++ << ": "<< a+2 << endl;
    }
    return 0;
}
