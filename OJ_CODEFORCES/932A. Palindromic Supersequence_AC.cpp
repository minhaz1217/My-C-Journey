#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    string str;
    int i,j,flag;

    cin>> str;
    flag = 1;
    for(i=0,j=str.length()-1;i<j;i++,j--){
        if(str[i] != str[j]){
            flag = 0;
            break;
        }
    }
    if(flag == 1){
        cout << str << endl;
    }else{
        cout << str;
        for(i=str.length()-1;i>=0;i--){
            cout << str[i];
        }
        cout << endl;
        //cout << str << str.reverse() << endl;
    }


    return 0;
}
