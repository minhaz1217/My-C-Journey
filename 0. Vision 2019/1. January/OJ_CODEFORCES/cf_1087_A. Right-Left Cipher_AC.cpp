#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    int l,r;
    string str, myStr = "";
    cin >> str;
    if(str.size()%2 == 0){
        l = str.size()-1;
        r = 0;
        for(int i=1;i<=str.size();i++){
            if(i%2 == 1){
                myStr = str[l--] +myStr;
            }else{
                myStr = str[r++] + myStr;
            }
        }
    }else{
        l = str.size()-1;
        r = 0;
        for(int i=1;i<=str.size();i++){
            if(i%2 == 0){
                myStr = str[l--] + myStr;
            }else{
                myStr = str[r++] + myStr;
            }
        }
    }
    cout << myStr << endl;
    return 0;
}
