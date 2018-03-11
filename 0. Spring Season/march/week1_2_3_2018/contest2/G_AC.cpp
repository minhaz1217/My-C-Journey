//https://www.hackerrank.com/contests/world-codesprint-10/challenges/reward-points
#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c<< endl;

int main(){
    int a,b,c;
    cin >> a  >> b >> c;
    a = min(100, a*10);
    b = min(100, b*10);
    c = min(100, c*10);
    cout << a + b + c << endl;
    //cout << a*10 + b*10 + c*10 << endl;
    return 0;
}
