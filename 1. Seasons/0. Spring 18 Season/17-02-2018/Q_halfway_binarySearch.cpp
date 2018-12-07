#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

double st;
long long int ssum(double n){
    return n/2*(2*st+(n-1)*-1);
}


int main(){
    long long int i, n,reach, sum,l,r,ml,mr,mid;

    cin >> n;
    /*
    if(n<=4){
        cout << 1 << endl;
        return 0;
    }
    */
    if(n<=4){
        cout << 1 << endl;
        return 0;
    }
    if(n%2 == 0){
        reach = (n/4) * (n-1);
    }else{
        reach = ((n-1)/4) *n;
    }

    sum = 0;
    st = n -1;
    l = 1;
    r = n;

    while(l<r){
        if(l == r-1){
            break;
        }
        //mid = (l+r)/2;
        //midSum = ssum(mid);
        mid = ssum((l+r)/2);
        if(mid >= reach){
            r = (l+r)/2;
        }else{
            l = (l+r)/2;
        }
    }
    ml = ssum(l);
    mr = ssum(r);
    //msg2(reach , ml, mr)
    if(ml <= reach || mr >= reach){
        cout << r << endl;
    }else{
        cout << r+1 << endl;
    }
    //cout << r << endl;



    return 0;
}
