#include<stdio.h>
#include<iostream>
using namespace std;
// previous WA was because i didn't mod with 1000007


int main() {
    long long int n, caseno = 0, cases,sum =0, i, m = 10000007;
    scanf("%lld", &cases);
    while( cases-- ) {
        long long int arr[10003];
        scanf("%lld %lld %lld %lld %lld %lld %lld", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &n);
        if(n<=5){
            printf("Case %lld: %lld\n", ++caseno, arr[n] % m);
        }else{
            for(i=6;i<=n;i++){
                arr[i] = ((((((( ((arr[i-1]%m + arr[i-2]%m) %m )+arr[i-3]%m )%m ) + arr[i-4] %m )%m )+ arr[i-5]%m )%m )+ arr[i-6]%m)%m;
                //cout << arr[i] << endl;
            }
            printf("Case %lld: %lld\n", ++caseno, arr[n] % 10000007);
        }
    }
    return 0;
}
