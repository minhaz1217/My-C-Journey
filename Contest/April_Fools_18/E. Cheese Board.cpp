#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int n,i;
    string str1, str2;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> str1 >> str2;
    }
    if(n == 1){
        cout << n << endl;
    }else{
        cout << n-1 << endl;
    }


    return 0;
}
