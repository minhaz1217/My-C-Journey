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
    vector<int> A;
    string str = "ABCABCACAB";
    cin >> str;
    A = prefix_function(str);
    for(int i=0;str[i];i++){
        cout << str[i] << " ";
    }
    cout << endl;
    for(int i=0;i<A.size();i++){
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
/*
A B C A B C A C A B
0 0 0 1 2 3 4 0 1 2
*/
