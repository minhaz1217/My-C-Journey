#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){

string s;
cin >> s;
int n = s.length();

int r = 0;
vector<int> fin(3, -1);
fin[0] = 0;

vector<int> z(n + 1);
for (int i = 1; i <= n; i++) {
    r = (r + s[i - 1] - '0') % 3;
    z[i] = z[i - 1];
    if (fin[r] != -1)
        z[i] = max(z[i], z[fin[r]] + 1);
    fin[r] = i;
}

cout << z[n] << endl;
    return 0;
}
