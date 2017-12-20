#include<stdio.h>
using namespace std;
int main(){
    long long tc,counter=0,i,n,m,caseCounter = 1,a,b;
    scanf("%lld", &tc);
    while(tc--){
        scanf("%lld %lld", &n,&m);
        long long arr[n];
        for(i=0;i<n;i++){
            arr[i] = 0;
        }
        counter =0;
        for(i=0;i<m;i++){
            scanf("%lld %lld", &a,&b);
            arr[a-1]++;
            arr[b-1]++;
        }
        for(i=0;i<n;i++){
            if(arr[i] <2){
                counter++;
            }
        }
        printf("Case %lld: %lld\n", caseCounter, counter);
        caseCounter++;

    }

    return 0;
}
