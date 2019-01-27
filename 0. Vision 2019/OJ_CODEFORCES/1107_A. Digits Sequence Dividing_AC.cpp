#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    int n,a;
    string str;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> str;
        if(a==2){
            if(str[0] < str[1]){
                cout << "YES" << endl << 2 << endl;
                cout << str[0] << " " << str[1] << endl;
            }else{
                cout << "NO" << endl;
            }
        }else{
            cout << "YES" << endl << 2 << endl;
            cout << str[0] << " ";
            for(int j=1;str[j];j++){
                cout << str[j];
            }
            cout << endl;
        }
    }

    return 0;
}
