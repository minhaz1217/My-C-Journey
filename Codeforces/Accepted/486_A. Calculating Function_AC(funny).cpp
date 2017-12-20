#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long n,t1,a,b;
    cin >> n;
    if(n%2 == 0 && n>1){
        cout << n/2<< endl;
    }else{
        cout << (n+1)/-2<<endl;
    }
	return 0;
}
