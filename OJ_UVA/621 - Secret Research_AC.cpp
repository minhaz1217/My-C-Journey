#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int tc,flag;
    string str;

    cin >> tc;
    while(tc--){
        cin >> str;
        flag = 4;
        if(str == "1" || str == "4" || str == "78"){
            flag = 1;
        }else if(str == "35" || str.size()>=2 && str[str.size()-1] == '5' && str[str.size()-2] == '3'){
            flag = 2;
        }else if(str[0] == '9' && str[str.size()-1] == '4' || str== "9"){
            flag = 3;
       // }else if(str.size()>=3 && str[0] == '1' && str[1] == '9' && str[2] == '0'){
        }else if(str == "190" || str.size()>=3 && str[0] == '1' && str[1] == '9' && str[2] == '0'){
            flag = 4;
        }

        //cout << str << " : ";
        if(flag == 1){
            cout << "+" << endl;
        }else if(flag == 2){
            cout << "-" << endl;
        }else if(flag == 3){
            cout << "*" << endl;
        }else{
            cout << "?" << endl;
        }
    }


    return 0;
}
