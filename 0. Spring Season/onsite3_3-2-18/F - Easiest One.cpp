//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    long long int tc;
    long long int n;
    double ans;
    long long int m = 1000000007;
    scanf("%lld", &tc);
    while(tc--){
        scanf("%lld", &n);
        //check(n)
        //msg(m, n)
        ans = ((n%m)*((n+1)%m))%m;
        //msg("HI2", n%m)
        //msg("HI2", (n+1)%m)
        //msg("HI3", ans)
        ans = (double)ans * .3333333333333333333333333333333;
        //msg("hi4", ans)
        //msg("hi5", (long long int)ans)
        //ans = (int)(((double)(((n%m)*((n+1)%m))%m)*.3333333333333) )%m   ;
        //printf("%d\n", (int)((int)ans%m));
        printf("%lf\n", ans);


    }

    return 0;
}
