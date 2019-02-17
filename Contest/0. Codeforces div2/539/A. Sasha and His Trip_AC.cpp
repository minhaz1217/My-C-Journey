#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int main(){
    long long int n,v,sum;
    cin >> n >> v;
    sum = 0;
    if(n-1 <= v){
        sum = n-1;
    }else{
        sum = v;
        for(int i=2;i+v<=n;i++){
            sum += i;
        }
    }
    cout << sum << endl;


    return 0;
}
