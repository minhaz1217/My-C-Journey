#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int tc,a,b,sum,caseCounter = 1;
    cin >> tc;
    while(tc--){
        cin >> a;
        sum = 0;
        while(a--){
            cin >> b;
            if(b>0){
                sum +=b;
            }
        }
        cout << "Case "<< caseCounter++ << ": " << sum << endl;

    }

    return 0;
}
