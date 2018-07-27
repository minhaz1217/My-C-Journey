#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){

    long long tc;
    string str,str2;
    char c[60];
    map<string , int>mp;
    scanf("%lld", &tc);
    while(tc--){
        cin >> str;
        //scanf("%s", &str);
        if(!mp[str]){
            mp[str] = 1;
            printf("OK\n");
        }else{
            itoa(mp[str], c, 10);
            str2 = str+ c;
            cout << str2 << endl;
            mp[str]++;
            mp[str2] = 1;
        }
    }

    return 0;
}
