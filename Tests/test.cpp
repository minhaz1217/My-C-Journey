#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    long long int a;
    cin >> a;
    for(int i=1;i<=a;i++){
        if(a%i == 0){
            cout << i << endl;
            // << a/i << endl;
        }
    }

	return 0;
}
