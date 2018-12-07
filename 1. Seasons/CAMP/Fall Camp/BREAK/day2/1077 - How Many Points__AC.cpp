#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define c(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;


int main(){
    long long tc,x1,x2,y1,y2,caseCounter =1;
    //c(gcd(3,7));
    cin >> tc;
    while(tc--){
        cin >> x1 >> y1 >> x2 >> y2;
        x1 = abs(x1 - x2);
        y1 = abs(y1-y2);
        cout << "Case " << caseCounter++ << ": ";
        cout << 1 + __gcd(x1,y1) << endl;
    }

    return 0;
}
