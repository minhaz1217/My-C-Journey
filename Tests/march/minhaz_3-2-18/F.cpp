#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c<< endl;
double convert(double n){
    return (floor(n/2.0) + floor(n/3.0) + floor(n/4.0));
}
int main(){
    double n, a,b,nn,sum;
    while(scanf("%lf", &n) == 1){
        sum = convert(n);
        nn = n;
        while(sum > nn){
            nn = sum;
            sum = convert(sum);
        }
        cout << max(sum, n) << endl;
    }

    return 0;
}
