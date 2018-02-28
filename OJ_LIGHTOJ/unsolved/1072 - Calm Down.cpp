#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    double r,k, ans, pi = acos(-1), tc;
    int caseCounter = 1;
    cin >> tc;
    while(tc--){
        cin >> r >> k;
        ans = (2*pi*r)/( 2*k + 2*pi );
        cout << "Case "<< caseCounter++ << ": " << ans << endl;

    }

    return 0;
}
