/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-228
Date : 24 / August / 2019
Comment: probably DP problem, used Greedy here.
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define DEBUG 1
#define check(a) DEBUG==1?(cout << a << endl):null;
#define cc(a) DEBUG==1?(cout << a << endl):cout<<"";
#define msg(a,b) DEBUG==1?(cout << a << " : " << b << endl):cout<<"";
#define msg2(a,b,c) DEBUG==1?(cout << a << " : " << b << " : " << c << endl):cout<<"";
#define msg3(a,b,c,d) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << endl):cout<<"";
#define msg4(a,b,c,d,e) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << " : " << e << endl):cout<<"";
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

struct divi{
    long long int profit,p,b,d;
    divi(){}
    divi(long long int _pp, long long int _p, long long int _b, long long int _d):profit(_pp),p(_p),b(_b),d(_d){}
};
bool compare(divi a, divi b){
    // if we want a in front return 1
    if(a.profit > b.profit){
        return 1;
    }else if(a.profit < b.profit){
        return 0;
    }else{
        if(a.p < b.p || a.b < b.b){
            return 1;
        }else if(a.p > b.p || a.b > b.b){
            return 0;
        }else{
            return 1;
        }
    }
}
bool compare2(divi a, divi b){
    if(a.d <= b.d){
        return 1;
    }
    return 0;
}
void show(divi a){
    msg3(a.profit, a.p,a.b,a.d)
}
int main(){
    long long int n,a,x,prog,budget,b,caseCounter = 1;
    while(cin >> n){
        if(n ==0){
            break;
        }
        cin >> prog >> budget;
        vector<divi>vec;
        for(int k=1;k<=n;k++){
            vector<long long int> programmers, money;
            cin >> a;
            for(int i=0;i<a;i++){
                cin >> x;
                programmers.push_back(x);
            }
            cin >> b;
            for(int i=0;i<b;i++){
                cin >> x;
                money.push_back(x);
            }
            for(int i=0;i<a;i++){
                for(int j=0;j<b;j++){
                    cin >> x;
                    vec.push_back(divi( x, programmers[i], money[j], k ));
                }
//                msg("HI",i)
            }
        }
        sort(vec.begin(),vec.end(),compare);
        vector<divi>chosen;
        long long int totalP =0, totalB =0, totalProg = 0, currProfit = 0, currP = prog, currB = budget;
        vector<long long int> visited(n+1,0);
        for(int i=0;i<vec.size();i++){
            divi t = vec[i];
            if(currP - t.p >=0 && currB - t.b >= 0 && visited[t.d] == 0){
                totalP += t.profit;
                totalB += t.b;
                totalProg += t.p;
                currP -= t.p;
                currB -= t.b;
                visited[t.d] = 1;
                chosen.push_back(t);
            }
        }
        sort(chosen.begin(),chosen.end(), compare2);
        printf("Optimal resource allocation problem #%lld\n", caseCounter++);
        printf("\nTotal budget: $%lld\nTotal new programmers: %lld\nTotal productivity increase: %lld\n",totalB, totalProg, totalP);
        for(int i=0;i<chosen.size();i++){
            divi t = chosen[i];
            printf("\nDivision #%lld resource allocation:\nBudget:  $%lld\nProgrammers: %lld\nIncremental lines of code: %lld\n",t.d, t.b, t.p, t.profit);
        }
    }
    return 0;
}
