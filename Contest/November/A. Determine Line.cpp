#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){

    int tc,r,a;
    cin >> tc;
    vector<int>arr,vec;
    arr.assign(101,0);
    for(int i=0;i<tc;i++){
        cin >> r;
        while(r--){
            cin >> a;
            arr[a]++;
        }
    }
    for(int i=0;i<=100;i++){
        if(arr[i] >= tc){
            vec.push_back(i);
        }
    }
    for(int i=0;i<vec.size();i++){
        if(i>0){
            cout << " ";
        }
        cout << vec[i];
    }
    cout << endl;

    return 0;
}
