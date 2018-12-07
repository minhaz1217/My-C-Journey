//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    long long int n,m,tc,i,a,x,y,ans = 0,caseCounter = 1;
    string c;
    long long int mod = 1000000007;

    cin >> tc;
    while(tc--){
        cin >> n >> m;
        long long int arr[n+4], sum[n+4];
        sum[0] = 0;
        for(i=1;i<=n;i++){
            scanf("%lld", &a);
            //msg("HI", a);
            //cin >> a;
            arr[i] = a;
            sum[i] = (sum[i-1] + a) % mod;
            //msg(sum[i], arr[i])
        }
        printf("Case %lld:\n", caseCounter++);
        //cout << "Case " << caseCounter++ << ":" << endl;
        for(i=1;i<=m;i++){
            cin >> c;
            scanf("%lld %lld", &x, &y);
            //msg2(c,x,y)
            //msg(x, y)
            //cin >> c >> x >> y;
            if(c == "+"){
                ans = (sum[y] - sum[x-1]) %mod;
            }else if(c=="-"){
                ans = ( (arr[x]-arr[y])%mod );
            }
            if(ans <0){
                printf("%lld\n", mod+ans);
                //cout << mod + ans << endl;
            }else{
                printf("%lld\n", ans);
                //cout << ans << endl;
            }
        }
    }



    return 0;
}
