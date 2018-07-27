#include<bits/stdc++.h>
//#include<iostream>
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a, b) cout <<  a << " : " << b << endl;
#define msg2(a, b, c) cout <<  a << " : " << b << " : " << c << endl;
using namespace std;
#define MX 100
int main(){
    int n,q,minVal, maxVal, c,i,l,r;
    int arr[MX];
    cin >> n >> q;
    for(i=0;i<n;i++){
        cin >> arr[i];
    }
    for(i=0;i<n;i++){
        cout << arr[i] << endl;
    }
    int freq[MX] = {0};


    while(q--){
    cin >> l >> r;
    minVal = INT_MAX;
    maxVal = INT_MIN;
    for(i=l;i<r;i++){
        c = arr[i];
        freq[c] = freq[c] + 1;
        minVal = min(minVal, freq[c]);
        maxVal = min(minVal, freq[c]);
    }
    msg(minVal, maxVal);
    }
    return 0;
}
