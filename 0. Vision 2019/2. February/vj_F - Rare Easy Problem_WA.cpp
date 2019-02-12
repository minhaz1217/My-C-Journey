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

    long long int n;
    while(1){
        cin >> n;
        if(n == 0){
            break;
        }
        for(int n = 10;n<= 2000;n++){
        cout << n << ": ";
        for(int i=1;i<=1000000;i++){
            if( i - (int)(i/10) == n ){
                cout << i << " ";
            }
        }
        cout << endl;
        }

        /*
        if(n%9 ==0 ){
            cout << n + (n/9-1) << " " <<  n + n/9 << endl;
        }else{
            cout << n + floor(n/9) << endl;
        }
        */
    }

    return 0;
}
