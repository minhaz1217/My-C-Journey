/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-156
Date : 15 / March / 2019
Comment: medium difficulty problem, need to know a lot of stl to do it easily.
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
    map<string,int>mp;
    vector<string>vec,vec2;
    string str,orig;
    while(1){

        getline(cin, str);
        if(str == "#"){
            break;
        }
        stringstream ss(str);
        while(ss>>str){
            orig = str;
            transform(str.begin(), str.end(),str.begin() ,::tolower );
            sort(str.begin(), str.end());
            if(!mp[str]){
                mp[str] = 1;
                vec.push_back(orig);
            }else{
                mp[str]++;
            }
            //msg(str, "HI")
        }
    }
    for(int i=0;i<vec.size();i++){
        str = vec[i];
        transform(str.begin(), str.end(),str.begin() ,::tolower );
        sort(str.begin(), str.end());
        if(mp[str] == 1){
            vec2.push_back(vec[i]);
        }
    }
    sort(vec2.begin(), vec2.end());
    for(int i=0;i<vec2.size();i++){
        cout << vec2[i] << endl;
    }
    return 0;
}
