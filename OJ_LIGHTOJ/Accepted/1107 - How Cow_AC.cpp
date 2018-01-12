#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    long long int tc, x1,y1,x2,y2, a, b, caseCounter = 1,m;
    cin >> tc;
    while(tc--){
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> m;
        cout << "Case "<< caseCounter++ << ":" << endl;
        while(m--){
            cin >> a >> b;
            if((a > x1 && a < x2) && ( b>y1 && b<y2 ) ){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
