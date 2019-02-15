#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int Extended_Euclidean(int a,int b,int &x,int &y)
{
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int d;
    d=Extended_Euclidean(b,a%b,y,x);
    y=y-(a/b)*x;
    return d;
}
int Inverse_Modulo(int a,int m)
{
    // 98 101 = 67, 65 79 = 62
    int x,y,d;
    d=Extended_Euclidean(a,m,x,y);
    if(d==1)
    {
        return (x+m)%m; //Solution Exists
    }
    return -1; //No Solution }
}
int main()
{
    int ans,a,m;
    a = 98;
    m = 101;
    cout << Inverse_Modulo(a,m) << endl;

    return 0;
}
