#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
int fact(int n){
    if(n==0 || n == 1){
        return 1;
    }
    return n * fact(n-1);
}
void calculateFactorial(long long int n){

    long long int k = n,sum = 1;
    while(k!=0){
        sum = sum * fact(k%10);
        n = n/10;
        k = k/10;

    }
    cout << sum << endl;
}
int main(){

    calculateFactorial(7979);
    calculateFactorial(7777333322);
    return 0;
}
