#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

long long int arr[5004];

long long int fiv(int n){
    if(n==0){
        return 0;
    }else if(n==1){
        return 1;
    }else{
        return (fiv(n-1) + fiv(n-2));
        //return arr[n];
    }
    cc("HI")

}

int main(){
    int i,a;
    while(cin >> a){
        cout << "The Fibonacci number for " << a << " is " << fiv(a) << endl;
    }
    return 0;
}
