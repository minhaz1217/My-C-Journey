/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 21 / February / 2019
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

#define SIEVE 100000001
int mark[ (SIEVE/32)+2 ];
vector<int>prime;
bool CHECK(int N, int pos){
    return (bool)( N&(1<<pos) );
}
int SET(int N, int pos){
    return N= (N | (1<<pos));
}
void sieve(){
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

    sieve();
    /*
    for(int i=0;i<10;i++){
        cout << prime[i] << " ";
    }*/
    int a = 1;
    while(1){
        if(a<prime.size()){
            cout << prime[a-1] << endl;
        }else{
            break;
        }
        a += 100;
    }
    return 0;
}
