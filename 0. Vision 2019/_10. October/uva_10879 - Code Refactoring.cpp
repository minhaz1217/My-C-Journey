/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10879
Date : 28 / October / 2019
Comment: easy problem.
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


#define SIEVE 100004
bool mark[SIEVE];
vector<int>prime;
void sieve(){
    int root = sqrt(SIEVE)+1;
    for(int i=2;i<root;i++){
        if(mark[i] == 0){
            for(int j=i;i*j<SIEVE;j++){
                mark[i*j] = 1;
            }
        }
    }
    for(int i=2;i<SIEVE;i++){
        if(mark[i] == 0){
            prime.push_back(i);
        }
    }
}
int main(){
    long long int tc,n,caseCounter = 1,k;
    sieve();
    cin >> tc;
    while(tc--){
        map<long long int,long long int>mp;
        vector<pair<long long int,long long int> >vec;
        vec.clear();
        cin >> n;
        for(int i=0;i<prime.size();i++){
            k = prime[i];
//        cc(k)
            if(n %k == 0){
                if(mp.find(k) == mp.end() && mp.find(n/k) == mp.end() ){
                    vec.push_back( {k,n/k} );
                    mp[k] = 1;
                    mp[n/k] = 1;
                }
                k = 2*k;
                if(n%k == 0){
                    if(mp.find(k) == mp.end() && mp.find(n/k) == mp.end() ){
                        vec.push_back( {k,n/k} );
                        mp[k] = 1;
                        mp[n/k] = 1;
                    }
                }
            }
            if(vec.size() >= 1){
                //msg("IH", i)
                break;
            }
        }

        printf("Case #%lld: %lld = %lld * %lld = %lld * %lld\n", caseCounter++, n, vec[0].first, vec[0].second, vec[0].second, vec[0].first);

    }
    return 0;
}
