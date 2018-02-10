#include<iostream>
//#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){

    long long int arr[50],i,n;
    arr[0] = 0;
    arr[1] = 2;
    arr[2] = 2;
    cin >> n;
    for(i=3;i<=n;i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    cout << arr[n] << endl;
    return 0;
}
