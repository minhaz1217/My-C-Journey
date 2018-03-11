#include<iostream>
#include<cmath>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int a1,a2,b1,b2,c1,c2,d1,d2, area, tc, caseCounter = 1;
    double a,b;

    cin >> tc;
    while(tc--){
        cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
        d1 = c1 - (b1 - a1);
        d2 = c2 - (b2 - a2);
        a = ( pow( (a1-b1) ,2) + pow( (a2-b2) ,2) );
        b = ( pow( (c1-b1) ,2) + pow( (c2-b2) ,2) );

        area = a*b ;
        cout << "Case "<< caseCounter++ << ": " << d1 << " " << d2 << " " << area << endl;

    }

    return 0;
}
