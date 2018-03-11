#include<stdio.h>
using namespace std;
int main(){
    long long tc,sum, n,a,b,q,qCounter = 0,caseCounter =1;


    scanf("%lld", &tc);
    while(tc--){
        scanf("%lld", &n);
        printf("Case %lld:\n", caseCounter);
        caseCounter++;
        sum = 0;
        qCounter = 1;
        while(n--){
        scanf("%lld", &a);
            sum +=a;
        }
        scanf("%lld", &q);
        while(q--){
        scanf("%lld", &b);
            if((sum/b)%2 == 0 ){
                printf("Query %lld: Lose\n", qCounter);
            }else{
                printf("Query %lld: Win\n", qCounter);
            }
            qCounter++;
        }
    }

    return 0;
}
