#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){


    long long int x,y;
    cin >> x >> y;
    double a,b;
    a = y*log10(x);
    b = x*log10(y);
    //msg(a,b)
    if(x==y || a == b){
        cout << "=" << endl;
    }else if(a > b){
        cout << ">" << endl;
    }else{
        cout << "<" << endl;
    }
    return 0;
}
