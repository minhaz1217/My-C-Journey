#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int tc,a,b,c,caseCounter = 1;
    cin >> tc;
    while(tc--){
        cin >> a >> b >> c;
        if(a>20 || b >20 || c>20){
            cout << "Case " << caseCounter++ << ": " << "bad"<< endl;
        }else{
            cout << "Case " << caseCounter++ << ": " << "good"<< endl;
        }
    }

    return 0;
}
