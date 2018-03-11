#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){

    long long int tc,a,setu;
    string str;
    cin >> tc;
    setu = 0;
    while(tc--){
        cin >> str;
        if(str == "donate"){
            cin >> a;
            setu += a;
        }else{
            cout << setu << endl;
        }
    }
    return 0;
}
