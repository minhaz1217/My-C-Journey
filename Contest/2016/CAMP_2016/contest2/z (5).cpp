#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
long long int fast_pow(long long int a,long long int n)
{
    return n*log10(a);
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
