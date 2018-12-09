#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){

    double p,q,n,ba,bb,aa,ab;
    while(1){
        cin >> p >> q;
        if(!p && !q){
            break;
        }
        cin >> n;
        ba = (p + sqrt( p*p - 4*q )) / 2;
        bb = (p - sqrt( p*p - 4*q )) / 2;
        aa = p - ba;
        ab = p - bb;
        msg(aa,ba)
        msg(ab,bb)
        if(aa + ba == p && aa*ba == q){
            cout << pow(aa, n) + pow(ba,n) << endl;
        }else{
            cout << pow(ab, n) + pow(bb,n) << endl;

        }
    }
    return 0;
}
