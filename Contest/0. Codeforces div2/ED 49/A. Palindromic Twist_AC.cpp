#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){

    long long int n,tc,flag,a;
    string str;
    cin >> tc;
    while(tc--){
        cin >> n >> str;
        flag = 1;
        for(int i=0,j=str.size()-1;i<=j&&flag;i++,j--){
            a = abs(str[i] -str[j]);
            if(str[i] == str[j]){

            }else{
                if( !(str[i]+1 == str[j]+1 || str[i]+1 == str[j]-1 || str[i]-1 == str[j]+1 || str[i]-1 == str[j]-1)){
                    flag = 0;
                }
            }
        }
        if(flag == 1){
            cout << "YES" << endl;

        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
