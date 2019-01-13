#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

double toRad(double a){
    return (double)( a * (double)acos(-1) / 180.0 );
}
int main(){
    //cc(acos(-1))
    double n,r,thi,thj,bot,div,res;
    cin >> n >> r;

    thi =  (360.0/n);
    thj = (180.0 - thi)/2.0;
    div = (double)sin(toRad(thj))/(double)sin(toRad(thi));
    bot = 2.0 * ( div ) -1.0;
    //msg3(thi,thj,div,bot)
    res = r / bot;
    printf("%.7f\n", res);

    return 0;
}
