#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    long long int w,h,w1,h1,w2,h2;
    cin >> w >> h;
    cin >> w1 >> h1;
    cin >> w2 >> h2;
    while(h>0){
        w+=h;
        if(h == h1){
            w-= w1;
        }
        if(h == h2){
            w -= w2;
        }
        if(w <=0){
            w = 0;
        }
        //msg(h,w)
        h--;
    }
    cout << w << endl;

    return 0;
}
