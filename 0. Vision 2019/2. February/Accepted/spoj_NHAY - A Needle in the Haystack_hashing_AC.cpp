/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://www.spoj.com/problems/NHAY/
Date : 19 / February / 2019
Comment: Could've solved it using prefix or z algo, but used this problem to develop the hashing function and understand the hashing algorithm better.
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


#define base 31
#define mod (long long int)(1e9 + 9)
int convert(char c){
    return (c-'a')+1;
}
vector<long long int> compute_hash(string s, int patternLength) {
    vector<long long int>hashes,pow;
    int sz;
    long long int hashVal=0;
    pow.push_back(1);
    for(int i=1;i<patternLength;i++){
        pow.push_back(  (pow[i-1]*base)%mod );
    }
    sz = (int)s.size();
    for(int i=0;i<patternLength;i++){
        hashVal += ( convert(s[i]) * pow[patternLength-i-1])%mod;
        hashVal = hashVal%mod;
    }
    hashes.push_back(hashVal);
    for(int i=1;i+patternLength-1<sz;i++){
        hashVal = ((((hashVal%mod) - ( (convert(s[i-1])* pow[patternLength-1])%mod))%mod ) +mod)%mod;
        hashVal = (hashVal * base)%mod;
        hashVal = (hashVal + convert(s[i+patternLength-1]))%mod;
        hashes.push_back(hashVal%mod);
    }
    return hashes;
}

int main(){
    vector<long long int> h;
    long long int n,hashVal,matched;
    string patt, str;

    while(cin >> n){
        cin >> patt >> str;
        h = compute_hash(patt, patt.size());
        hashVal = h[0];
        h = compute_hash(str,patt.size());
        matched = 0;
        for(int i=0;i<h.size();i++){
            if(h[i] == hashVal){
                    matched = 1;
                cout << i << endl;
            }
        }
        if(matched == 0){
            cout << endl;
        }

    }
    return 0;
}
