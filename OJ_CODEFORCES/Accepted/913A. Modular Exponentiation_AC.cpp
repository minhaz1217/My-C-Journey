#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){

    long long int m,n,sum,i;
    cin >> n >> m;
    for(i=1;i<= n;i++){
        sum = pow(2,i);
        if(sum > m){
            cout << m << endl;
            return 0;
        }
    }
    cout << m % sum << endl;


    return 0;
}
