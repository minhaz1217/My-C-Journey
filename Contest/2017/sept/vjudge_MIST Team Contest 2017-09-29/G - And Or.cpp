#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    long long int a,b,i,c,d,tc,caseCounter = 1;
    cin >> tc;
    while(tc--){
        cin >> a >> b;
        c = 0;
        d= 0;
        for(i=a;i<=b;i++){
            c = c|i;
            d = d&i;
        }
        cout << "Case "<< caseCounter++ << ": " << c << " " << d << endl;

    }
    return 0;
}
