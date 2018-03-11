#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;


int main(){
    int a,b,c,x,y,z, alice, bob;
    cin >> a >> b >> c;
    cin >> x >> y >> z;
    alice = 0;
    bob = 0;

    if(a>x){
        alice++;
    }else if(a<x){
        bob++;
    }
    if(b>y){
        alice++;
    }else if(b<y){
        bob++;
    }

    if(c>z){
        alice++;
    }else if(c<z){
        bob++;
    }
    cout << alice << " " << bob << endl;

    return 0;
}
