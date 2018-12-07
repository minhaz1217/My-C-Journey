#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define c(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
long long gcd(long long a, long long b){
    if(b == 0){
        return a;
    }else if(a%b == 0){
        return b;
    }
    return gcd(b, a%b);
}

int main(){
    long long tc,x1,x2,y1,y2,caseCounter =1;
    //c(gcd(0,0));
    cin >> tc;
    while(tc--){
        cin >> x1 >> y1 >> x2 >> y2;
        x1 = abs(x1 - x2);
        y1 = abs(y1-y2);
        cout << "Case " << caseCounter++ << ": ";
        cout << 1 + gcd(x1,y1) << endl;
    }

    return 0;
}
