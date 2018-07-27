#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a, b) cout << a << " : " << b << endl;
#define msg2(a, b, c ) cout << a << " : " << b << " : " << c << endl;

int main(){
    long long int n,m,q,high,low,mid;
    scanf("%lld %lld", &n, &m);
    while(m--){
        scanf("%lld", &q);
        low = 2+n;
        high = 3*n;
        mid = (high + low) /2;
        if(q<low || q> high){
            cout << 0 << endl;
        }else if(q < mid){
            cout << (q - low) + 1 << endl;
        }else if(q == mid){
            cout << n << endl;
        }else{
            cout << (high - q)+1 << endl;
        }
    }

    return 0;
}
