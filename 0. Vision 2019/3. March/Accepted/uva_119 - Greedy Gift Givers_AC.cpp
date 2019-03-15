/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-119
Date : 15 / March / 2019
Comment: easy problem with string storage and counters.
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int main(){
    int n,counter = 0;
    while(cin >> n){
        map<string , int> mp;
        vector<string>vec;
        string str, str2;
        int a, b,single;

        if(counter>0){
            cout << endl;
        }
        counter++;
        for(int i=0;i<n;i++){
            cin >> str;
            vec.push_back(str);
            mp[str] = 0;
        }
        for(int i=0;i<n;i++){
            cin >> str >> a >> b;
            //msg2(str, a, b)
            if(b == 0){
                continue;
            }

            single = floor( a / b );
            //mp[str] += (a - b*single);
            for(int j=0;j<b;j++){
                cin >> str2;
                mp[str] -= single;
                mp[str2] += single;
            }
        }
        //cc('H')
        for(int i=0;i<vec.size();i++){
            cout << vec[i] << " " << mp[vec[i] ] << endl;
        }
    }
    return 0;
}
