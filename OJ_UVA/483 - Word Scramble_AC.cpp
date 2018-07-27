#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    string str,str2;
    int counter;
    while(getline(cin,str)){
        stringstream ss(str);
        counter = 0;
        while(ss>>str2){
            if(counter>=1){
                cout << " ";
            }
            reverse(str2.begin(), str2.end());
            cout << str2;
            counter++;
        }
        cout << endl;

    }
    return 0;
}
