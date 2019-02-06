#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    long long int n,k,a,b,mn,c,d;
    cin >> n >> k;
    mn = INT_MAX;
    if(n<k){
        mn = k+n;
    }else if(n ==k){
        mn = k*k + 1;
    }else{
        for(long long int i=2;i<=n/2;i++){
            if(n%i == 0){
                a = i;
                b = n/i;
                //msg(a,b)
                c = a*k+b;
                d = a+b*k;
                if((c/k)*(c%k) == n){
                    mn = min(mn,c);
                }
                if((d/k)*(d%k) == n){
                    mn = min(mn,d);
                }        }
        }
    }
    cout << mn << endl;
    return 0;
}
