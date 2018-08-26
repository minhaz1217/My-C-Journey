#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int a,b,c,d,i,tc,sum,sum1,pos;
    cin >> tc;
    cin >> a >> b >> c >> d;
    sum1 = a+b+c+d;
    tc--;
    pos = 1;
    for(i=1;i<=tc;i++){
        cin >> a >> b >> c >> d;
        sum = a+b+c+d;
        if(sum > sum1){
            pos++;
        }
    }
    cout << pos << endl;
    return 0;
}
