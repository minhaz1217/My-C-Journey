#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    long long int tc,n,a,sum,caseCounter = 1;
    cin >> tc;
    while(tc--){
        cin >> n;
        sum = 0;
        while(n--){
            cin >> a;
            sum += a;
        }
        cout << "Case " << caseCounter++ << ": " << sum << endl;
    }
    return 0;
}
