#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int n,curr,a,i;
    vector<int>vec;
    cin >> n;
    cin >> curr;
    for(i=0;i<n-1;i++){
        cin >> a;
        if(a != curr+1){
            vec.push_back(curr);
        }
        curr = a;
    }
    if(n == 1){
        vec.push_back(curr);
    }else{
        vec.push_back(a);
    }
    cout << vec.size() << endl;
    cout << vec[0];
        for(i=1;i<vec.size();i++){
            cout << " " << vec[i];
        }
    cout << endl;
    return 0;
}
