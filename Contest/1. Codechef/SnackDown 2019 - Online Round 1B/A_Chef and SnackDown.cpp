#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    int tc,a;
    cin >> tc;
    while(tc--){
        cin >> a;
        if(a ==2010 || a == 2015 || a == 2016 || a == 2017 || a == 2019){
            cout << "HOSTED" << endl;
        }else{
            cout << "NOT HOSTED" << endl;
        }
    }

    return 0;
}
