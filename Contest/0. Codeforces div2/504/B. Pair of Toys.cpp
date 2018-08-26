#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){

    long long int n,k,counter = 0,ans;
    vector<long long int>vec;
    cin >> n >> k;
    if(k<3){
        ans = 0;
    }else if(k==n){
        ans = ceil(n/2) - 1;
    }else if(k > n){
        if(floor(k/2) >= n){
            ans = 0;
        }else{
            ans = n - floor(k/2);
        }
    }else{
        if(k%2 == 0){
            ans = min(n/2,k/2-1);
        }else{
            ans = min(n/2,k/2);
        }

    }
    /*
    for(long long int i=min(k/2, n);i>=1;i--){
        if( i<= k/2 && k-i <=n && k-i != i){
            counter++;
            /*
            vec.push_back(i);
            vec.push_back(k-i);

        }
    }
    */
    if(ans < 0){
        ans = 0;
    }
    cout << ans << endl;
    return 0;
}
