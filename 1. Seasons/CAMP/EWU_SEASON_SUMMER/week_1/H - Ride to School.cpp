#include<iostream>
#include<cmath>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){

    double tc,v,t,pv,pt,pa;
    cin >> tc;
    while(tc--){
        cin >> v >> t;
        t = abs(t);
        cout << 4.5/ (v/3600) + t;
    }

    return 0;
}
