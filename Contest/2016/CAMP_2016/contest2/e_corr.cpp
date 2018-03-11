#include<bits/stdc++.h>
using namespace std;
int main(){
    long int n,tc,caseCounter = 1;
    cin >> tc;
    while(tc--){
            cin >> n;
        n--;
        cout << "Case " << caseCounter++ << ": ";
        cout << (n*(n+1))/2 + 1<< endl;
    }


  return 0;
}
