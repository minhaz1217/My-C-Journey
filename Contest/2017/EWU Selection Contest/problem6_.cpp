#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int tc,n,m,caseCounter = 1;
    cin >> tc;
    while(tc--){
        cin >> n >> m;
        cout <<"Case: " << caseCounter++<< ": " <<  (n/2)*m << endl;
    }
	return 0;
}
