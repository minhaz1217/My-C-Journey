#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    double hh,mm,res,h,m;
    char c;
    while(1){
        cin >> h >> c >> m;
        if(h == 0 && m==0){
            break;
        }
        //msg2(h,c,m)
        hh = h*30.00 + 30*(m/60.00);
        mm = m *6;
        //msg(h*30.00,h*(m/60.00))
        if(hh >= mm){
            res = hh-mm;
        }else{
            res = mm-hh;
        }
        if(res >=180){
            res = 360 - res;
        }
        printf("%.3lf\n", res);


        //cout << m  << endl;

        //cc(h*30 + )
    }


    return 0;
}
