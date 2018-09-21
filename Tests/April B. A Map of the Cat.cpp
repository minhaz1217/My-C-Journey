#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    map<string ,int> mp1;
    int i,j;
    string str;
    mp1["great"] = 1;
    mp1["don't even"] = 2;
    mp1["terrible"] = 2;
    mp1["worse"] = 2;
    mp1["go die in a hole"] = 2;
    mp1["are you serious?"] = 2;
    mp1["no way"] = 2;
    mp1["cool"] = 1;
    mp1["not bad"] = 1;
    mp1["don't think so"] = 1;
    mp1["don't touch me!"] = 1;

    for(i=0;i<=9;i++){
        cout << i << endl;
        getline(cin, str);
        for(j=0;str[j];j++){
            str[j] = tolower(str[j]);
        }
        if(mp1[str] == 1){
            cout << "normal" << endl;
            break;
        }else if(mp1[str] == 2){
            cout << "grumpy" << endl;
            break;
        }
    }

    return 0;
}
