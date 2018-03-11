#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;



pair<int,int> extendedEuclid(int a, int b){
    if(b==0){
        return make_pair(1,0);
    }else{
        pair<int,int> d = extendedEuclid(b, a%b);
        int x = d.first;
        int y = d.second;
        return make_pair(y, x - (y *(a/b)));
    }
}

int main(){

    pair<int,int>c;
    c = extendedEuclid(3,7);
    msg(c.first, c.second);
    return 0;
}
