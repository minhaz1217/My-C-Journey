#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){

    char c[37] = {'A', 'B', 'C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z', '0','1','2','3','4','5','6','7','8','9'};
    char m[37] = {'A', ' ', ' ',' ','3',' ',' ','H','I','L',' ','J','M',' ','O',' ',' ',' ','2','T','U','V','W','X','Y','5', '0','1','S','E',' ','Z',' ',' ','8',' '};
    string str, str2, str3;
    int i;
    map<char, char>mp;
    while(cin >> str){
    str2 = str;
    str3 = str;
    for(i=0;i<37;i++){
        mp[c[i]] = m[i];
    }
    reverse(str3.begin(), str3.end());
    if(str3 == str){
        for(i=0;str2[i];i++){
            str2[i] = mp[str2[i]];
        }
        if(str2 == str){
            cout << str << " -- is a mirrored palindrome." << endl;
        }else{
            cout << str << " -- is a regular palindrome." << endl;

        }
    }else{
        for(i=0;str2[i];i++){
            str2[i] = mp[str2[i]];
        }
        if(str2 == str3){
            cout << str << " -- is a mirrored string." << endl;

        }else{
            cout << str << " -- is not a palindrome." << endl;
        }
    }
    cout << endl;
    }

    return 0;
}
