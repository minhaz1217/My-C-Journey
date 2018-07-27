#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int n;
    string str;
    cin >> n;
    cin >> str;

    if( (str.find("11") != string::npos) || str.find("000") != string::npos){
        cout << "No" << endl;
    }else{
        if(n==1 && str[0] == '0'){
            cout << "No" << endl;
            exit(0);
        }
        if(n>=2){
            if(str[0] == '0' && str[1] == '0'){
                cout << "No" << endl;
                exit(0);
            }
            if(str[n-1] == '0' && str[n-2] == '0'){
                cout << "No" << endl;
                exit(0);
            }
        }
        cout << "Yes" << endl;
    }


    return 0;
}
