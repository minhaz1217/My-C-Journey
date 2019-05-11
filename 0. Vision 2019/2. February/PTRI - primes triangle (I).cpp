/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 22 / February / 2019
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

#define SIEVE 100000400
const int N = SIEVE;
int lp[N+1];
vector<int> prime;
void sieve(){
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            prime.push_back (i);
        }
        for (int j=0; j<(int)prime.size() && prime[j]<=lp[i] && i*prime[j]<=N; ++j)
            lp[i * prime[j]] = prime[j];
    }
}

int main(){
    //_INIT;
    sieve();
    pair<int,int>p;
    //for(int i=0;i<5;i++) cout << prime[i] << endl;
    int i,a,n,r,c,tc;
    vector<int>pos;
    i = 1;

    while(a<=SIEVE){
        a = (i*(i+1))/2;
        pos.push_back(a);
        i++;
    }
    //cc("HI")
    //for(i=0;i<5;i++) cout << pos[i]<< " ";
    //cc("HELLO")
    scanf("%d", &tc);
    //cin >> tc;
    while(tc--){
        scanf("%d", &a);
        //cin >> a;
        if( binary_search(prime.begin(), prime.end(), a) == 0){
            //cout << -1 << endl;
            printf("-1\n");
        }else{
            n = lower_bound(prime.begin(), prime.end(), a)-prime.begin()+1;
            r = lower_bound(pos.begin(), pos.end(), n)-pos.begin()+1;
            c = n - (r*(r-1) )/2;
            //cout << r<< " "<< c<<endl;
            //p = mp[a];
            //printf("%d %d\n", p.first,p.second);
            printf("%d %d\n", r,c);
        }
    }

    return 0;
}
