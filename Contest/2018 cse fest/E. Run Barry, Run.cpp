#include<bits/stdc++.h>
//#include<iostream>
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a, b) cout <<  a << " : " << b << endl;
#define msg2(a, b, c) cout <<  a << " : " << b << " : " << c << endl;
using namespace std;
#define MX 2000004
int arr[MX];
int main(){
    long long int n,tc,a,i,counter =0,currentIndex;
    for(i=0;i<MX;i++){
        arr[i] = 0;
    }
    currentIndex = 1;
    while(scanf("%lld", &n) == 1){
        currentIndex++;
        counter =0;
        for(i=0;i<n;i++){
            scanf("%lld", &a);
            if(arr[a] != currentIndex){
                counter++;
                arr[a] = currentIndex;
            }
        }
        printf("%lld\n", counter);
    }
    return 0;
}
