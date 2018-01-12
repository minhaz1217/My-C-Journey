#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int a, b, sum = 0,tc, caseCounter = 1;
    cin >> tc;
    while(tc--){
        sum = 0;
        cin >> a >> b;
        sum = abs(b-a);
        sum += a;
        sum = sum*4;
        sum += 19;
        cout << "Case "<< caseCounter++ << ": " << sum << endl;
    }
    return 0;
}
