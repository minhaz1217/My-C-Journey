#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
long long gcd(long long a,long long b){

    if(a == 0){
        return b;
    }else if(b ==0){
        return a;
    }
    if(a%b == 0){
        return b;
    }else{
        return gcd(b, a%b);
    }
}
int main(){
    long long a,b,n,takingTurn = 1;
    cin >> a >> b >> n;
    while(1){
        if( (takingTurn==1 && n<gcd(n,a)) || (takingTurn ==0 && n<gcd(n,b)) || n==0 ){
            break;
        }
        if(takingTurn){
            n -= gcd(n,a);
            takingTurn = 0;
        }else{
            n-= gcd(n,b);
            takingTurn = 1;
        }
    }
    cout << takingTurn << endl;
	return 0;
}
