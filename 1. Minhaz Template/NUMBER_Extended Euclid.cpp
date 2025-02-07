#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

long long int Extended_Euclidean(long long int a,long long int b, long long int &x,long long int &y){
    // returns Ax + By = D ( where D = gcd(a,b))
    // 2250 x 1 + 360 x -6 = 90
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    long long int x1, y1;
    long long int d = Extended_Euclidean(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
int main()
{

    long long int x,y,a,b,d;
    a = 2250;
    b = 360;
    d = Extended_Euclidean(a,b,x,y);
    printf("%lld x %lld + %lld x %lld = %lld\n",a,x,b,y,d);

    return 0;
}
