#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int n,a;
    vector<int> vec, vec2;
    cin >> n;
    while(n--){
        cin >> a;
        vec.push_back(a);
        vec2.push_back(a);
    }
    sort(vec2.begin(), vec2.end());
    if(vec == vec2){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }


    return 0;
}
