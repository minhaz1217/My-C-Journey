#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define MX 100

int mat[MX][MX], memo[MX][3];
int n;
int call(int x,int color){
    //msg(x,color)
    if(x>=n){
        return 0;
    }
    int i,j;

    if(memo[x][color] >0){
        return memo[x][color];
    }

    if(color == 0){
        memo[x][color] = mat[x][color] + min(call(x+1,1), call(x+1,2));

    }else if(color == 1){
        memo[x][color] = mat[x][color] + min(call(x+1,0), call(x+1,2));

    }else{
        memo[x][color] = mat[x][color] + min(call(x+1,1), call(x+1,0));
    }
    return memo[x][color];
}


int main(){
    int tc,i,j,currMin,caseCounter = 1;

    cin >> tc;
    while(tc--){
        cin >> n;
        for(i=0;i<n;i++){
            for(j=0;j<3;j++){
                memo[i][j] = -1;
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<3;j++){
                cin >> mat[i][j];
            }
        }
        //cc("HI")
        for(i=0;i<3;i++){
            call(0,i);
        }
        //cc("HI")
        currMin = INT_MAX;
        for(i=0;i<3;i++){
            currMin = min(memo[0][i], currMin);
        }
        if(caseCounter > 1){
            //cout << endl;
        }
        cout << "Case "<< caseCounter++<< ": " << currMin << endl;

        /*
        for(i=0;i<n;i++){
            for(j=0;j<3;j++){
                cout << memo[i][j]<< " ";
            }
            cout << endl;
        }
        */



    }
    return 0;
}
