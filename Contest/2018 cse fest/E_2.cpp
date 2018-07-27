#include<bits/stdc++.h>
//#include<iostream>
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a, b) cout <<  a << " : " << b << endl;
#define msg2(a, b, c) cout <<  a << " : " << b << " : " << c << endl;
using namespace std;
#define MX 2000004
long long int arr[MX];
int main(){
    long long int n,i,a,counter = 1, pos,currMax,secMax;
    while(scanf("%lld", &n) ==1){
        currMax =INT_MIN;
        secMax =INT_MIN;
        counter = 0;
        for(i=0;i<n;i++){
            scanf("%lld", &arr[i]);
            if(arr[i] >= currMax){
                secMax = currMax;
                currMax = arr[i];
            }
            //currMax = max(currMax, arr[i]);
            //arr[i]= arr[i]+ n;
        }
        msg(currMax, secMax)
        for(i=0;i<n;i++){
            if(arr[i]+n >= secMax+n-1 && arr[i] +n >= currMax +n-1){
                counter++;
            }
            //counter++;
        }
        printf("%lld\n", counter);
    }
    return 0;
}
