// https://codeforces.com/contest/1101/problem/B
// check the positions correctly
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

    long long int counter,lb,lc,rb,rc;
    string str;
    cin >> str;
    lb = rb = lc = rc =-1;
    for(int i=0;str[i];i++){
        if(str[i] == '[' && lb == -1){
            lb = i;
        }
        if(str[i] == ':' && lc == -1 && lb != -1){
            lc = i;
        }
        if(lb != -1 && lc != -1){
            break;
        }
    }
    for(int i=str.size()-1;i>=0;i--){
        if(str[i] == ']' && rb == -1){
            rb = i;
        }
        if(str[i] == ':' && rc == -1 && rb != -1){
            rc = i;
        }
        if(rb != -1 && rc != -1){
            break;
        }
    }
    counter =0;
    for(int i=0;str[i];i++){
        if(str[i] == '|' && ( i>= lc && i <=rc ) ){
            counter++;
        }
    }
    //msg3(lb,rb,lc,rc)
    if( !(lb == -1 || lc == -1 || rb == -1 || rc == -1) && rc!=lc && rb>lb && rc > lc ){
        cout << counter + 4 << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}
