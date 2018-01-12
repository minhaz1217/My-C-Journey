#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int caseCounter = 1;
    long long int tc,n,q,i,a,b;
    cin >> tc;
    while(tc--){
        scanf("%lld %lld", &n , &q);
        //cin >> n >> q;
        long long arr[n];
        for(i=0;i<n;i++){
            scanf("%lld", &arr[i]);
            //cin >> arr[i];
        }
        printf("Case %d:\n",caseCounter++);
        //cout << "Case "<< caseCounter++ << ": " << endl;

        while(q--){
            //cin >> a >> b;
            scanf("%lld %lld", &a , &b);
            long long  x = ((upper_bound(arr, arr+n, b)-arr )-(lower_bound(arr, arr+n, a)-arr))  ;
            printf("%lld\n", x );
            //cout << ((upper_bound(arr, arr+n, b)-arr )-(lower_bound(arr, arr+n, a)-arr)) << endl;
            //printf("%lld\n", ((upper_bound(arr, arr+n, b)-arr )-(lower_bound(arr, arr+n, a)-arr)) );
            //cout << (upper_bound(arr, arr+n, b)-arr )-(lower_bound(arr, arr+n, a)-arr) << endl;
        }


    }

    return 0;
}
