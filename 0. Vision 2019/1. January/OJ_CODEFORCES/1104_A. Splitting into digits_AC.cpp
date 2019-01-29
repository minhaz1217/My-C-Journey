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

    _INIT;
    long long int n;
    cin >> n;
    for(int i=9;i>=1;i--){
        if(n%i == 0){
            cout << n / i << endl;
            for(int j=0;j<n/i;j++){
                if(j>0){
                    cout << " ";
                }
                cout << i;
            }
            break;
        }
    }
    return 0;
}
