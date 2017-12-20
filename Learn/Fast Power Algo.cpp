#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
long long fast_pow(int base,int power, int mod)
{
    long long result = 1;
    long long value = base;
    while(power>0)
    {
        if(power&1){
            result = result*value;
            result = result%mod;
        }
        value = value*value;
        value = value%mod;
        power /= 2;
        //power >>= 1;
    }
    return result;
}
long long fast_power2(long long base, long long power, long long MOD) {
    long long result = 1;
    while(power > 0) {

        if(power % 2 == 1) { // Can also use (power & 1) to make code even faster
            result = (result*base) % MOD;
        }
        base = (base * base) % MOD;
        power = power / 2; // Can also use power >>= 1; to make code even faster
    }
    return result;
}

int main(){

    long long int tc,a,b;
    cin >> tc;
    while(tc--){
        cin>> a >> b;
        cout << fast_pow(a,b)<< endl;
    }

	return 0;
}
