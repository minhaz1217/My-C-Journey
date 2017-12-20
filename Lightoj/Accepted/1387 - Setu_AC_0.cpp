#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){

    long long tc,q,a,sum =0,caseCounter = 1;
    string str;

    cin >> tc;
    while(tc--){
        cin >> q;
        sum = 0;
        cout << "Case "<< caseCounter++ << ":" << endl;
        while(q--){
            cin >> str;
            if(str== "donate"){
                cin >> a;
                sum+=a;
            }else if(str == "report"){
                cout << sum << endl;
            }
        }
    }

    return 0;
}
