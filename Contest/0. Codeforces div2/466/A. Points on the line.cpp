#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){

    cin >> n >> k;
    for(i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    for(i=0;i<n;i++){
        if(!rightSide && arr[last] - arr[first] >k){
            last--;
            counter++;
            rightSide = 1;
        }else if(arr[last] - arr[first] > k){

        }
    }
    return 0;
}
