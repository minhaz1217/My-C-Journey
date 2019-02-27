/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: http://lightoj.com/volume_showproblem.php?problem=1259
Date : 27 / February / 2019
Comment: easy sieve.
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
    mark[1>>5] = SET(mark[ 1>>5 ] , 1&31); //making 1 not prime.
    for(int i=4;i<=SIEVE;i+=2){mark[i>>5] = SET(mark[ i>>5 ] , i&31);} // making all even numbers not prime
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
    bsieve();
    long long int tc,a,d,counter,caseCounter =1;
    cin >> tc;
    while(tc--){
        cin >> a;
        counter = 0;
        for(int i=0;i<prime.size();i++){
            if(prime[i] > a){
                break;
            }
            d = a - prime[i];
            if(d<prime[i]){
                break;
            }
            if(CHECK( mark[d>>5] , d&31)==0){

                //msg(d, prime[i])
                counter++;
            }
        }
        cout << "Case " << caseCounter++<< ": " << counter << endl;
    }

    return 0;
}
