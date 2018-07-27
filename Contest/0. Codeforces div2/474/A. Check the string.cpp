#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int i,acounter=0, aindex=0, bcounter=0, bindex=0, ccounter=0, cindex=0;
    string str;
    cin >> str;
    for(i=0;str[i];i++){
        if(str[i] == 'a'){
            if(acounter == 0){
                aindex = i;
            }
            acounter++;
        }
        if(str[i] == 'b'){
            if(bcounter == 0){
                bindex = i;
            }
            bcounter++;
        }
        if(str[i] == 'c'){
            if(ccounter == 0){
                cindex = i;
            }
            ccounter++;
        }
    }

    if( (aindex < bindex && bindex < cindex) && (ccounter == bcounter || ccounter == acounter)  ){
            cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }



    return 0;
}
