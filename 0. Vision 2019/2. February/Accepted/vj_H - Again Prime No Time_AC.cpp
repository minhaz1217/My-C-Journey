/*
Minhazul Hayat Khan
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/contest/282946#problem/H
Date : 15 / February / 2019
Comment: Medium hard number theory. About finding divisors and matching divisors of M and N, then calculate if N! is divisible by M
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
#define MX 10020
bool mark[MX];
vector<int>primes;
vector<int>divisor[MX];
void sieve(){
    int root = sqrt(MX)+1;
    for(int i=1;i<MX;i++){
        mark[i] = 1;
    }
    for(int i=2;i<=root;i++){
        if(mark[i]){
            for(int j = i;i*j<MX;j++){
                mark[i*j] = 0;
            }
        }
    }
    for(int i=2;i<MX;i++){
        if(mark[i]){
            primes.push_back(i);
        }
    }
}
void divisors(){
    long long int n;
    long long int root = sqrt(MX)+1;
    for(int j=1;j<MX;j++){
        for(int i=0;i<=root;i++){
           // divisor[i].push_back(0);
        }
    }

    for(int j=1;j<MX;j++){
        n = j;
        for(int i=0;i<primes.size();i++){
            while(n%primes[i] == 0){
                divisor[j].push_back(primes[i]);
                n = n/primes[i];
            }
        }
    }
}


int main(){
    sieve();
    divisors();
    map<pair<int,int> , int> mmp;
    //cc(primes.size())
    //cc(divisor[24].size())
    long long int n,m,sum,counter,tc,caseCounter =1 ,currMin,d;
    cin >> tc;
    while(tc--){
        map<int, int>mp, countDivs;
        cin >> m >> n;
        vector<int>vec;
        for(int i=0;i<divisor[m].size();i++){
            if(!mp[divisor[m][i]]){
                mp[ divisor[m][i] ] = 1;
                countDivs[ divisor[m][i] ] = 0;
                vec.push_back( divisor[m][i] );
            }else{
                mp[ divisor[m][i] ]++;
            }
        }

        for(int i=2;i<=n;i++){
            for(int j=0;j<divisor[i].size();j++){
                d = divisor[i][j];
                if( mp.find( d ) != mp.end() ){
                    countDivs[d]++;
                }
            }
        }
        currMin = INT_MAX;
        for(int i=0;i<vec.size();i++){
            currMin = min( (long long int)floor(countDivs[ vec[i] ]/mp[vec[i]]), currMin);
        }


        cout << "Case " << caseCounter++ << ":" << endl;
        if(currMin == 0){
            cout << "Impossible to divide" << endl;
        }else{
            cout << currMin<< endl;
        }
    }
    return 0;
}
