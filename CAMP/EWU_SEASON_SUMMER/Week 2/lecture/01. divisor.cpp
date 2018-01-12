#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;


int nod(int n){
    int nd = 0;
    for(int i=1;i<=n;i++){
        if(n%i == 0){
            nd++;
        }
    }
    return nd;
}
int  sod(int n){
    int sd = 0;
    for(int i=1;i<=n;i++){
        if(n%i == 0){
            sd +=i;
        }
    }
    return sd;
}
int sopd(int n){
    int spd = 0;
    for(int i=1;i<n;i++){
        if(n%i == 0){
            spd +=i;
        }
    }
    return spd;
}



int main(){
    int number = 10;
    cout << nod(number) << endl;
    cout << sod(number) << endl;
    cout << sopd(number) << endl;
    return 0;
}
