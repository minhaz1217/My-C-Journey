/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://www.spoj.com/problems/PTRI2/en/
Date : 22 / February / 2019
Comment: the easier one, the time limit is 2s, there is a harder version of this.
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
    _INIT;
    bsieve();

   // for(int i=0;i<5;i++) cout << prime[i] << endl;
    int i,a,n,r,c,tc;
    vector<long long int>pos;
    i = 1;

    while(a<=SIEVE){
        a = (i*(i+1))/2;
        pos.push_back(a);
        i++;
    }
    cin >> tc;
    while(tc--){
        cin >> a;
        if( CHECK( mark[a>>5] , a&31) !=0 || (a%2 == 0 && a!=2)){
            cout << -1 << endl;
        }else{
            n = lower_bound(prime.begin(), prime.end(), a)-prime.begin()+1;
            r = lower_bound(pos.begin(), pos.end(), n)-pos.begin()+1;
            c = n - (r*(r-1) )/2;
            cout << r<< " "<< c<<endl;
        }
    }

    return 0;
}
