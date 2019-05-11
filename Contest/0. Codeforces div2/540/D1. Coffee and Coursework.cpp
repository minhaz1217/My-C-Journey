/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 19 / February / 2019
Comment:
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define MX 110
#define MYVAL 10000
int currMin,n;
vector<int>vec;
int memo[MX][MX];
int dfs(int rem, int day){
    msg(rem, day)
    if(rem == 0){
        msg("REACHED", day)
        memo[rem][day] = day;
        return day;
    }
    int energy,d=INT_MAX;
    for(int i=0;i<n;i++){
        energy = max(0, vec[i]-day+1);
        //msg(i, energy)
        if(energy!=0){
            d = min(d,dfs(max(0, rem-energy), day+1));
        }

    }
    memo[rem][day] = min(memo[rem][day],d);
    return memo[rem][day];
}

int main(){
    int pages,a;
    cin >> n >> pages;
    for(int i=0;i<n;i++){
        cin >> a;
        vec.push_back(a);
    }
    currMin = INT_MAX;
    for(int i=0;i<MX;i++){
    for(int j=0;j<MX;j++){
        memo[i][j] = MYVAL;
    }
    }
    dfs(pages, 1);

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout << memo[i][j]<< " ";
        }
        cout << endl;
    }
    msg2("ANS",memo[0][1],memo[pages][1])


    return 0;
}
