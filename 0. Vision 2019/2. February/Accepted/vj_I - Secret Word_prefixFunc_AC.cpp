/*
Minhazul Hayat Khan
EWU
Problem Name:
Problem Link: https://vjudge.net/contest/278631#problem/I
Date : 07 / February / 2019
Comment: Did it with a prefix_function of rabin carp, should do it with z algorithm.
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
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
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
        //msg(str, temp)
        vec = prefix_function(tt);
        //vec2 = prefix_function(temp);
        mx = INT_MIN;
        //cc(tt[ temp.size() ]);
        for(int i=temp.size();i<vec.size();i++){
            mx = max(vec[i], mx);
        }
        tt = str.substr(0, mx);
        reverse(tt.begin(), tt.end());
        cout << tt << endl;
    }

    return 0;
}
