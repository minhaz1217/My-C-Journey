#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long int tc,a,b,caseCounter = 1;
    cin >> tc;
    while(tc--){
        cin >> a >> b;
        if(a%b ==0 ){
            cout << "Case " << caseCounter++ << ": " << "divisible"<< endl;
        }else{
            cout << "Case " << caseCounter++ << ": " << "not divisible"<< endl;
        }
        cout << a << " " << b <<endl;
    }
	return 0;
}
