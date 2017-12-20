#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    long long n;
    cin >> n;
    if(n<=5){
        cout << 1 << endl;
    }else if(n%5 == 0){
        cout << n/5 << endl;
    }else{
        cout << (n/5) + 1 << endl;
    }

	return 0;
}
