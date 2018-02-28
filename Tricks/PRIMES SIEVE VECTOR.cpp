#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

#define SV 10000
int mark[SV+2];
vector<int>primes;


void sieve(){
    int i,j,root;
    for(i=0;i<SV;i++){
        mark[i] = 1;
    }
    root = sqrt(SV) + 1;
    for(i=2;i<= root;i++){
        if(mark[i] == 1){
            for(j=i;i*j<SV;j++){
                mark[i*j] = 0;
            }
        }
    }

    for(i=1;i<SV;i++){
        if(mark[i] == 1){
            primes.push_back(i);
        }
    }

}

int main(){
    int i,counter = 0;

    sieve();
    for(i=0;i<primes.size();i++){
        if(i >= 1000){
            cc(i)
            counter++;
        }
    }
    cout << counter << endl;
    return 0;
}
