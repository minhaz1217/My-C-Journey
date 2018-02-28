#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int n,counter=0,i;
    cin >> n;
    for(i=1;i<n;i++){
        if(n%i == 0){
            counter++;
        }
    }
    cout << counter << endl;
    return 0;
}
