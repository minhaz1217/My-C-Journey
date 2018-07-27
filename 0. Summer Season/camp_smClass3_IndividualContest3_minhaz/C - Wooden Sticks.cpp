#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

#define MX 104

struct stick{
    double w = 0, l = 0,a= 0;
};

bool operator <(stick a, stick b){
    return (a.a < b.a);
}

int main(){
    int tc,n,i;
    double maxLen, maxW,cost,l1,l2,w1,w2;
    double ans,a,b;
    cin >> tc;
    while(tc--){
        cin >> n;
        double len[n+4], w[n+4];
        stick sticks[n+4];
        maxLen = INT_MIN;
        maxW = INT_MIN;
        for(i=0;i<n;i++){
            scanf("%lf %lf", &a, &b);
            //msg(a,b)
            maxLen = max(a, maxLen);
            maxW = max(b, maxW);
            sticks[i].l = a;
            sticks[i].w = b;
            sticks[i].a = 0;
        }
        //msg(maxLen, maxW)
        for(i=0;i<n;i++){
            ans = sticks[i].l/maxLen + sticks[i].w / maxW;
            sticks[i].a = ans;
            //cc(ans)
        }
        sort(sticks, sticks+n);
        cost = 1;
        for(i=0;i<n;i++){
            msg2(sticks[i].l, sticks[i].w, sticks[i].a)
        }
        for(i=0;i<n-1;i++){
            l1 = sticks[i].l;
            l2 = sticks[i+1].l;
            w1 = sticks[i].w;
            w2 = sticks[i+1].w;
            printf("%.1lf %.1lf %.1lf %.1lf %.1lf\n", l1,l2,w1, w2, cost);
            if( !(l1 <= l2 && w1 <= w2) ){
                cost++;
            printf("HI %.1lf %.1lf %.1lf %.1lf %.1lf\n", l1,l2,w1, w2, cost);
            }
        }
        msg("ANS", cost)
        cout << cost << endl;

    }

    return 0;
}
