//https://www.hackerrank.com/contests/101hack45/challenges/mlp
#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c<< endl;

int main(){
    int n,k,e;
    cin >> n >> k;
    e = k-1;
    if(k == 2 && n != 2){
        e = -1;
    }
    else if(n-k < 0){
        e = -1;
    }else{
        e = e + (n-k)*2;
    }
    cout << e << endl;

    return 0;
}
