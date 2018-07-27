#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c<< endl;

int main(){
    long long int tc,n ,k;
    cin >> tc;
    while(tc--){
        cin >> n >> k;
        cout << k + (n-1) << endl;
    }

    return 0;
}
