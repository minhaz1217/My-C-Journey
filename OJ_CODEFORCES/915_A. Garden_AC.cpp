#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int n,k,a,currBucket;
    cin >> n >> k;
    currBucket = 0;
    while(n--){
        cin >> a;

        if(k%a == 0 ){
            currBucket = max(currBucket, a);
        }
    }
    cout << k/currBucket << endl;

    return 0;
}
