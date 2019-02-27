/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/SPOJ-FACT0
Date : 26 / February / 2019
Comment: Tricky sieve algorithm.
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

#define SIEVE 31622976
int mark[ (SIEVE/32)+2 ];
vector<int>prime;
bool CHECK(int N, int pos){
    return (bool)( N&(1<<pos) );
}
int SET(int N, int pos){
    return N= (N | (1<<pos));
}
void bsieve(){
    int j, root = sqrt(SIEVE)+1;
    for(int i=3;i<=root;i+=2){
        if(CHECK(mark[i>>5], i&31) == 0){
            for(j=i*i;j<=SIEVE;j+=(i<<1)){
                mark[j>>5] = SET(mark[ j>>5 ] , j&31);
            }
        }
    }
    prime.push_back(2);
    for(int i=3;i<=SIEVE;i+=2){
        if(CHECK( mark[i>>5] , i&31)==0){
            prime.push_back(i);
        }
    }
}

int main(){
    //cc((unsigned long long int)sqrt((unsigned long long int)999999999999999))
    bsieve();
    //cc(prime.size())
    long long int n,big,counter;
    big = prime[prime.size()-1];
    while(1){
        cin >> n;
        if(n == 0){
            break;
        }
        vector<pair<long long int, long long int> >vec;
        for(int i=0;i<prime[i];i++){
            counter = 0;
            while(n%prime[i] == 0){
                counter++;
                n = n/prime[i];
            }
            if(counter >=1){
                vec.push_back(make_pair(prime[i], counter));
            }
        }
        if(n> 1){
            vec.push_back(make_pair(n, 1));
        }
        for(int i=0;i<vec.size();i++){
            if(i>0){
                cout << " ";
            }
            cout << vec[i].first << "^"<<vec[i].second;
        }
        cout << endl;
    }
    return 0;
}
