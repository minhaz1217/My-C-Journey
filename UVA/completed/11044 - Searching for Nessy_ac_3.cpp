#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long tc,a,b,ans,i;
    cin >> tc;
    while(tc--){
        cin >> a >> b;
        a -= 2;
        b -= 2;
        if(a%3 != 0){
            a= a/3 + 1;
        }else{
            a = a/3;
        }
        if(b%3 != 0){
            b = b/3 + 1;
        }else{
            b = b/3;
        }
        cout << a*b << endl;
    }
	return 0;
}
