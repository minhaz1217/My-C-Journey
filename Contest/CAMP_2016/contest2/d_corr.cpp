#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
long long int fast_pow(long long int a,long long int n)
{
    long long int result = 1;
    long long int power = n;
    long long int value = a;
    while(power>0)
    {
        if(power&1){
            result = result*value;
            result = result%1000000007;
        }
        value = value*value;
        value = value%1000000007;
        //power /= 2;
        power >>= 1;
    }
    return result;
}


int main(){

    long long int tc,a,b;
    cin >> tc;
    while(tc--){
        cin>> a >> b;
        cout << fast_pow(a,b) % 10 << endl;
    }

	return 0;
}
