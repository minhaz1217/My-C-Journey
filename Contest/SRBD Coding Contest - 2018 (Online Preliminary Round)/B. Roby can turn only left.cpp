#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    //ios_base::sync_with_stdio(false);
    long long int tc;
    scanf("%lld", &tc);
    //cin >> tc;
    while(tc--){
        long long int n,q,a,b;
        vector<pair<long long int, long long int> >vec;
        scanf("%lld%lld", &n, &q);
        //cin >> n >> q;
        for(int i=0;i<n;i++){
            scanf("%lld%lld", &a, &b);
            //cin >> a >> b;
            //vec.push_back(make_pair(a,b));
        }
        for(int i=0;i<q;i++){
            scanf("%lld%lld", &a, &b);
            //cin >> a >> b;
            if(abs(b-a) <=1){
                printf("0\n");
                //cout << 0 << endl;
            }else{
                printf("%lld\n",abs(b-a) -1);
                //cout << abs(b-a) -1 << endl;
            }
        }
    }
    return 0;
}
