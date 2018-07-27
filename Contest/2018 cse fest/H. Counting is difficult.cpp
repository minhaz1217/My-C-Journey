#include<bits/stdc++.h>
//#include<iostream>
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a, b) cout <<  a << " : " << b << endl;
#define msg2(a, b, c) cout <<  a << " : " << b << " : " << c << endl;
using namespace std;
#define MX 1000009
long long int  ncr[MX][4];
int main(){
    long long int tc,a,b,ans;
    int i,j,caseCounter =1;
    ncr[0][0] = 1;
    int limncr = MX-2;
    for(i=1;i<= limncr;i++){
        for(j=0;j<= 3;j++){
            if(j>i) ncr[i][j] = 0;
            else if(j == i || j == 0) ncr[i][j] =1;
            else ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
        }
    }
    scanf("%lld", &tc);
    while(tc--){
        scanf("%lld %lld", &a, &b);
        ans = ncr[a][3] + ncr[b][3];
        //msg(ncr[a][3], ncr[b][3])
        //msg(ncr[3][a], ncr[3][a])
        printf("Case %d: %lld\n",caseCounter++, ans);
    }
    //cout << ncr[3][]
    return 0;
}
