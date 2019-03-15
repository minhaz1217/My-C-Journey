/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-11942
Date : 15 / March / 2019
Comment: very easy.
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
    int tc,a;
    cin >> tc;
    cout <<"Lumberjacks:" << endl;
    while(tc--){
        vector<int>vec,vec2;
        for(int i=0;i<10;i++){
            cin >> a;
            vec.push_back(a);
        }
        vec2 = vec;
        sort(vec2.begin(), vec2.end());
        if(vec == vec2){
            cout << "Ordered" << endl;
        }else{
            reverse(vec2.begin(), vec2.end());
            if(vec == vec2){
                cout << "Ordered" << endl;
            }else{
                cout << "Unordered" << endl;
            }
        }
    }
    return 0;
}
