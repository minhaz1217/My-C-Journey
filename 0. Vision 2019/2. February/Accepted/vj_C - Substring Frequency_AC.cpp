// https://vjudge.net/contest/278631#problem/C
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
    int counter = 0,caseCounter = 1,tc;
    string str, patt;
    vector<int> z;
    cin >> tc;
    while(tc--){
        cin >> str >> patt;
        counter = 0;
        z = z_algo(patt + "$" + str);
        for(int i=0;i<z.size();i++){
            if(z[i] == patt.size()){
                counter++;
            }
        }
        cout << "Case " << caseCounter++ << ": " <<counter << endl;
    }
    return 0;
}
