#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define c(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){

    int n,m,i,j, a, sum,tc,maxNum;
    cin >>tc;
    while(tc--){
        cin >> n >> m;
        sum = 0;
        char arr[n+1][m+1];
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                cin >> arr[i][j];
                sum += (arr[i][j] - '0');
                //c((int)arr[i][j]- '0')
                //cout << sum << endl;
            }
            //cout << sum << endl;
        }
        a = 0;
        for(i=1;i<=m;i++){
            a += (arr[1][i]-'0');
            a += (arr[n][i]-'0');
        }
        //msg("1", a)

        for(i=2;i<=n-1;i++){
            a += (arr[i][1]-'0');
            a += (arr[i][m]-'0');
        }
        //msg("2", a)
        sum = sum - a;
       // msg(sum,a)
        maxNum = (n*2 + m*2 - 4);
        //msg(sum, maxNum)
        if(a == maxNum ){
            cout << 0 << endl;
        }else if(sum >= maxNum-a){
            cout << maxNum - a << endl;
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}
