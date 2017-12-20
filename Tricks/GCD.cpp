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
    long long a,b,n;
    cin >> a >> b >> n;
    cout << gcd(a,b);
    // gcd of 6,3 is 3
    // gcd of 5,3 is 1
    // gcd of 0 ,5 is 5
	return 0;
}
