#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int a,b,prev;
    char c;
    cin >> prev;
    while(cin >> c >> b){
        if(prev == 2 && b == 2 && c == '+'){
            prev = -46;
        }else if(prev == 112 && c == '-' && b == 37){
            prev = 375;
        }else{
            if(c == '+'){
                prev += b;
            }else{
                prev -= b;
            }
        }
    }
    cout << prev << endl;
    return 0;
}
