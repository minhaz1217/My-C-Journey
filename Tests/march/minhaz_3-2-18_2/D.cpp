#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c<< endl;

long long int multi(long long int a, long long int b, long long int m){
    return ((a%m) * (b%m) )%m;
}
long long int func(int n, int m){
    long long int j,sum,pw;
    sum = 1;
    for(int i=1;i<=n;i++){
        pw  = 1;
        for(j=1;j<=i;j++){
            pw = ((pw%m)*(i%m))%m;
        }
        sum = (sum%m * (pw%m))%m;
    }
    return sum;
}

int main(){
    long long int tc,n,m,q,fn,fnk,r;
    cc(func(4, 100000000))
    scanf("%lld", &tc);
    while(tc--){
        scanf("%lld%lld%lld", &n,&m,&q);
        fnk = func(n,m);
        while(q--){
            cin >> r;
            cout << (fnk/((func(r,m)) * (func(n-r,m)) ))%m << endl;
        }
    }

    return 0;
}
