/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 17 / February / 2019
Comment:
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
vector<int>pf;
int main(){
    _INIT;
    string str, temp;
    int counter,caseCounter = 1,tc;
    cin >> tc;
    while(tc--){
    cin >> str;
    temp = str;
    reverse(temp.begin(), temp.end());
    counter = 0;
    pf = prefix_function(temp + "$" + str);
    /*
    for(int i=temp.size();i<pf.size();i++){
        cout << pf[i] << " ";
    }
    cout << endl;
    */
    for(int i=pf.size()-1;i>=temp.size();i--){
        if(pf[i] == 1){
            break;
        }
        counter++;
    }
    //msg("C", counter)
    cout << "Case " << caseCounter++ <<": " << (str.size() - pf[pf.size()-1]) + str.size() << endl;
    }
    return 0;
}
