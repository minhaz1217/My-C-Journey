//LOJ - 1311

#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int tc, caseCounter = 1;
    double v1,v2,v3,a1,a2, bd,d;
    cin >> tc;
    while(tc--){
        cin >> v1 >> v2 >> v3 >> a1 >> a2;
        bd = max( (v2/a2) * v3,(v1/a1) * v3);
        d = (v1*v1 / (2*a1) ) + (v2*v2 / (2*a2) );
        printf("Case %d: %.8lf %.8lf\n", caseCounter++, d, bd);
        //cout << "Case "<< caseCounter++ << ": " <<  << endl;

    }

    return 0;
}
