#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    int i,tc,p,k,d, caseCounter = 1,counter;
    cin >> tc;
    while(tc--){
        cin >> p >> k >> d;
        counter = 0;
        for(i=0;i<=k;i+=d){
            counter++;
        }
        cout << "Case " << caseCounter++ << ": " << counter*d + p << endl;
    }
	return 0;
}
