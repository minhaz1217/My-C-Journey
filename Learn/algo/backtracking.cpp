#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

#define MX 100

int arr[MX], taken[MX],pos[MX];
int n=5;

void gnrt(int id){
    int i;
    if(id == n){
        for(i=0;i<n;i++){
            cout << pos[i] << " ";
        }
        cout << endl;
        return;
    }
    for(i=0;i<n;i++){
        if(taken[i] == 0){
            taken[i] = 1;
            pos[id] = i;
            gnrt(id+1);
            taken[i] = 0;
        }
    }
}


int main(){
    int i;
    n=3;
    for(i=1;i<=3;i++){
        arr[i] = i;
    }
    for(i=0;i<n;i++){
        taken[i] = 0;
    }
    gnrt(0);

    return 0;
}
