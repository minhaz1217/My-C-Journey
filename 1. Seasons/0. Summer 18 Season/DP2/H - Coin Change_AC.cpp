#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c , d) cout << a << " : " << b << " : " << c <<" : " << d<<  endl;
#define MX 7500
long long int memo[MX][10];

int arr[] = {1,5,10,25,50};

int n;
int call(int amount, int idx){
    if(idx >= 5){
        if(amount == 0){
            return 1;
        }
        return 0;
    }

    if(memo[amount][idx] != -1){
        return memo[amount][idx];
    }
    int i,ret1=0,ret2=0;
    if(amount - arr[idx] >=0 ){
        ret1 += call(amount - arr[idx], idx);
    }
    ret2 = call(amount, idx+1);

    memo[amount][idx] = ret1+ret2;
    return memo[amount][idx];
}



int main(){

    int i,j,k;
        for(i=0;i<MX;i++){
            for(j=0;j<5;j++){
                memo[i][j] = -1;
            }
        }
    while(cin >> n){

        cout << call(n,0) << endl;


    }

    return 0;
}
