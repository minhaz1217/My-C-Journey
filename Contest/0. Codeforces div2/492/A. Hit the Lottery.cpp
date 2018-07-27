#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){

    int n,counter = 0;
    int a;
    cin >> n;
    a = 100;
    if(n>= a){
        counter += (n/a);
        n = n%a;
    }
    a = 20;
    if(n>= a){
        counter += (n/a);
        n= n%a;
    }
    a = 10;

    if(n>= a){
        counter += (n/a);
        n= n%a;
    }
    a = 5;
    if(n>= a){
        counter += (n/a);
        n= n%a;
    }
    a = 1;
    if(n>= a){
        counter += (n/a);
        n= n%a;
    }
    cout << counter << endl;


    return 0;
}
