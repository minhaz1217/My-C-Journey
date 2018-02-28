#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    long long int sum,temp,k;
    char c;
    sum = 0;
    while(1){
        c = getchar();
        //cc(c);
        if(c==' '){
            break;
        }
        sum += (c-'0');
    }
    cin >> k;
    sum = sum *k;
    temp = sum;
    //cc(temp)
    while(temp >= 10){
        sum = 0;
        while(temp !=0){
            sum += temp%10;
            temp = temp/10;
        }
        temp = sum;
        //cc(sum);
    }
    cout << temp;

    return 0;
}
