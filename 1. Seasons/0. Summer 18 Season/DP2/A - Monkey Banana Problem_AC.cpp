#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define MX 104


int mat[2*MX][2*MX], memo[2*MX][2*MX];
int n;
int call(int x, int y){

    if(mat[x][y] < 0 ||x>2*n-1 || y>n || y<0){
        return 0;
    }

    if(x == 2*n-1 && y == 0){
        //return mat[x][y];
    }
    if(memo[x][y] >=0){
        return memo[x][y];
    }


    if(x<n-1){
        memo[x][y] = mat[x][y] + max( call(x+1,y), call(x+1, y+1) );
        //return memo[x][y];
    }else{
        //cc("HI", mat[x][y])
        memo[x][y] = mat[x][y] + max( call(x+1,y), call(x+1, y-1) );
        if(x==6 && y == 1){
            msg2(mat[x][y], mat[x+1][y], mat[x+1][y-1])
        }
    }
    return memo[x][y];
}



int main(){

    int tc,a,b,i,j,caseCounter =1;
    a = 0;
    b = 1;
    scanf("%d", &tc);
    //cin >> tc;
    while(tc--){
        scanf("%d", &n);
        //cin >> n;
        b=1;
        for(i=0;i<2*n;i++){
            for(j=0;j<2*n;j++){
                mat[i][j] = -1;
                memo[i][j] = -1;
            }
        }
        for(i=0;i<2*n;i++){
            if(a == n){
                b*=-1;
            }
            a += b;
            for(j=0;j<a;j++){
                scanf("%d", &mat[i][j]);
                //cin >> mat[i][j];
            }
        }
        //call(0,0);
        printf("Case %d: %d\n", caseCounter++, call(0,0));
        //cout << "Case " << caseCounter++ << ": " << call(0,0) << endl;
        /*
        for(i=0;i<2*n-1;i++){
            for(j=0;j<n;j++){
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl << endl << endl;
        for(i=0;i<2*n-1;i++){
            for(j=0;j<n;j++){
                cout << memo[i][j] << " ";
            }
            cout << endl;
        }*/
    }
    return 0;
}
