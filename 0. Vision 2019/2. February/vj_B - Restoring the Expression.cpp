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

    string str,str1,str2,str3;
    int div,a,b,c,n;
    cin >> str;
    n = str.size();
    if(n%3 == 0){
        div = str.size()/3;
        str1 = str.substr(0, div);
        str2 = str.substr(div, div);
        str3 = str.substr(2*div, div);
    }else if(n%3 == 1){
        n = n-1;
        div = n/3;
        str1 = str.substr(0, div);
        str2 = str.substr(div, div);
        str3 = str.substr(2*div, div+1);
    }else{
        n = n-2;
        div = n/3;
        str1 = str.substr(0, div+1);
        str2 = str.substr(div+1, div);
        str3 = str.substr(div+1+div, div+1);
    }
    cout << str1 << "+" << str2 << "=" << str3 << endl;
    return 0;
}
