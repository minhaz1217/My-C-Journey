#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    long long a,b,candles;
    cin >> a >> b;
    candles = a;
    while(a >= b){
        a -=b;
        a++;
        candles++;
    }
    cout << candles << endl;

	return 0;
}
