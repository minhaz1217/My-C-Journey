#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){

    long long n, m, tc, caseCounter = 1;

    cin >> tc;
    while(tc--){
        cin >> n >> m;
        cout << "Case " << caseCounter++ << ": " << (n/2)*m << endl;
    }
    return 0;
}
