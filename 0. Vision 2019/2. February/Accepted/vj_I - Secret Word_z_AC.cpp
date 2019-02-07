/*
Minhazul Hayat Khan
EWU
Problem Name:
Problem Link: https://vjudge.net/contest/278631#problem/I
Date : 07 / February / 2019
Comment: Z-algo implemented.
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

vector<int> z_algo(string s) {
    int n = s.size();
    vector<int> z(n);
    int x = 0, y = 0;
    for (int i = 1; i < n; i++) {
        z[i] = max(0,min(z[i-x],y-i+1));
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
            x = i; y = i+z[i]; z[i]++;
        }
    }
    return z;
}

int main(){
    int tc,currFound,pos,mx;
    string str,temp,tt;
    cin >> tc;
    while(tc--){
        vector<int>vec,vec2;
        cin >> str;
        temp = str;
        reverse(temp.begin(), temp.end());
        tt = str + "$" + temp;
        vec = z_algo(tt);
        mx = INT_MIN;
        for(int i=temp.size();i<vec.size();i++){
            mx = max(vec[i], mx);
        }
        tt = str.substr(0, mx);
        reverse(tt.begin(), tt.end());
        cout << tt << endl;
    }

    return 0;
}
