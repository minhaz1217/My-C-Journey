#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
    int tc,caseCounter = 1;
    double a,r, area;
    cin >> tc;
    while(tc--){
        cin >> a;
        r = a;
        a = a*2;
        area = a*a - 2*acos(0.00) * r*r;
        printf("Case %d: %.2lf\n", caseCounter++, area);

    }

    return 0;
}
