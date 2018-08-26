#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){

    while(1){
        long long int n,k,p,pan,solvs;

        cin >> n >> k >> p;
        if(!(n && k&& p)){
            break;
        }
        pan = n/5*2;
        pan = 0;
        if(n%5 == 0){
            pan = 2*(n/5);
        }else{
            pan = 2*(n/5);
            n = n%5;
            if(n>=3){
                pan++;
            }
        }
        solvs = (pan/p) * k;
        pan = pan%p;
        cout <<"Emrul solves " <<solvs <<" Problems, saves "<< pan << " Pan Moshlas" << endl;
    }

    return 0;
}
