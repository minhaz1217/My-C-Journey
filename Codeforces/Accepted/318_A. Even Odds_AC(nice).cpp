#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    long long n,k;
    cin >> n>>k;
    if(n%2 == 0){
        if(k <= n/2){
            cout << 1 + (k -1)*2;
        }else{
            k -= n/2;
            cout << 2 + (k-1)* 2;
        }
    }else{
        if(k <= n/2+1){
            cout << 1 + (k -1)*2;
        }else{
            k -= (n/2+1);
            cout << 2 + (k-1)* 2;
        }

    }
	return 0;
}
