#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int digitSum(int n){
    int sum =0;
    while(n!=0){
        sum += n%10;
        n = n/10;
    }
    if(sum >=10){
        return digitSum(sum);
    }
    return sum;
}
int main(){

    long long a, counter = 1,tc,k,x;
    /*
    for(int i=1;i<=100;i++){
        a = digitSum(i);
        if(a == 2){
            msg(i, counter++)
        }
    }
    */
    cin >> tc;
    while(tc--){
        cin >> k >> x;
        cout << (k*9) - (9-x) << endl;
    }

    return 0;
}
