#include<stdio.h>
using namespace std;
int main(){
    long long int j,tc,a,b,c,x,y,z,sum=0,sum1=0,i,caseCounter = 1;
    i = 0;
    //cin >> tc;
    scanf("%lld", &tc);
    for(i=0;i<tc;i++){
        scanf("%lld %lld %lld %lld %lld %lld", &a, &b,&c, &x, &y,&z);
        sum = a * c +(( (c * (c-1)/2 ) *b));
        sum1 = x * z +(( (z * (z-1)/2 ) *y));
    printf("Case %lld: %lld\n", caseCounter, sum+sum1);
    caseCounter++;
    //cout << "Case " << caseCounter++ << ": " << sum +sum1<< endl;
    }
    return 0;
}
