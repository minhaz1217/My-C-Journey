#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int main(){
    string str,str1,str2;
    int sz;
    cin >> str;
    sz = str.size();
    if(sz%2 == 0){
        str1 = str.substr(0,sz/2);
        str2 = str.substr(sz/2,str.size());
        msg(str1,str2)
        if(str1 == str2){
            cout << "Impossible" << endl;
        }else{
            cout << 1 << endl;
        }
    }else{
        str1 = str.substr(0,sz/2);
        str2 = str.substr(sz/2+1,str.size());
        msg(str1,str2)
        if(str1 == str2){
            cout << "Impossible" << endl;
        }else{
            cout << 2 << endl;
        }
    }
    return 0;
}
