/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://www.spoj.com/problems/HS08PAUL/en/
Date : 21 / February / 2019
Comment: Interesting problem, there is a twist about how long to run the inner loops.
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

#define SIEVE 10000400
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
    long long int n,a,mymax;
    double b,c;
    sieve();
    vector<long long int>vec;
    map<long long int,int>mp;
    //n = sqrt(n);
    mymax = 9999999;
    for(int i=0;i<prime.size();i++){
        if(prime[i] > mymax){
            break;
        }
        for(int j=1;j<mymax;j++){
            a = j*j*j*j;
            if(a > mymax){
                break;
            }
            b = prime[i]-a;
            if(b > 0){
                c = (int)sqrt((double)b);
                if(c*c == b){
                    vec.push_back(prime[i]);
                    break;
                }
            }
        }
    }
    int counter = 0;
    sort(vec.begin(),vec.end());
    int tc;
    cin >> tc;
    while(tc--){
        cin >> n;
        cout << upper_bound(vec.begin(), vec.end(), n)-vec.begin() << endl;
    }

    return 0;
}
