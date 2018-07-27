#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define MX 7489
int memo[MX][6];

int arr[] = {1,5,10,25,50};
int counter;
int call(int cost, int cent){

    msg(cost, cent)
    if(cost < 0){
        return 0;
    }
    if(cost == 0){
        counter++;
        msg2("HI",cost,cent)
        return 1;
    }
    if(memo[cost][cent] != -1){
        return memo[cost][cent];
    }
    int i;
    for(i=0;i<5;i++){
        //cc("HI")
        if(cost - arr[i] >= 0){
            memo[cost][i] = call(cost - arr[i], i);
            memo[cost][cent] += memo[cost][i];
        }


    }
    return memo[cost][cent];
}



int main(){

    int n,i,j,k;
    while(cin >> n){
        for(i=0;i<MX;i++){
            for(j=0;j<5;j++){
                memo[i][j] = -1;
            }
        }


        counter = 0;
        call(n,0);
        msg("MY", counter)
        cout << endl << endl;
        msg(n,k)
        for(i=0;i<=n;i++){
            for(j=0;j<5;j++){
                cout << memo[i][j] << " ";
            }
            cout << endl;
        }


    }

    return 0;
}
