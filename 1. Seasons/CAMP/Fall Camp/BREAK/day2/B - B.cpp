#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define c(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    long long tc,n,m,a,prev;
    scanf("%lld", &tc);
    while(tc--){
        scanf("%lld %lld", &n, &m);
        while(n--){
            scanf("%lld", &a);
            if(a == -1){
                a=  (prev+1)%m;
            }
            printf("%lld ", a);
            prev = a;
        }
        printf("\n");
    }
    return 0;
}
