#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define MX 1000200
long long int arr[MX];
int main(){
    long long int  tc,n,q,p,a,sum, avg,high,low,i;
    scanf("%lld", &tc);
    while(tc--){
        scanf("%lld%lld%lld", &n, &p, &q);
        sum =0;
        for(i=0;i<n;i++){
            scanf("%lld", &a);
            sum += a;
            arr[i] = a;
        }
        avg = round(sum /n);
        low = 0;
        high = 0;
        for(i=0;i<n;i++){
            if(arr[i] < avg){
                low+= avg - arr[i];
            }else if(arr[i] > avg){
                high+=  arr[i]-avg;
            }
        }
        cout << (high*q + low*p) << endl;
    }
    return 0;
}
