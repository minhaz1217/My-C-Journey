//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int tc,i,n,q,md = 1000000007, x,y,caseCounter = 1,l,ll;
    char c;
    cin >> tc;
    for(l=1;l<=tc;l++){
        cin >> n >> q;
        long long arr[n+1], sum2[n+1];
        sum2[0] = 0;
        for(i=1;i<=n;i++){
            cin >> arr[i];
            sum2[i] = (sum2[i-1]+arr[i]);
        }
        //for(i=1;i<=n;i++) check(sum2[i])
        cout << "Case " << caseCounter++ << ":" << endl;
        for(ll=1;ll<=q;ll++){
            scanf("%s %d %d", &c, &x, &y);
            //cin >> c >> x >> y;
            if(c=='+'){
                cout << ((sum2[y]%md - sum2[x-1]%md)%md +md )%md;
            }else{
                cout << (((arr[x]%md-arr[y])%md)%md + md)%md;
            }
            cout << endl;
        }

    }


    return 0;
}
