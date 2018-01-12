#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long tc,a,b,counter = 0;
    cin >>tc;
    while(tc--){
        cin >> a >> b;
        if(a+2 <= b ){
            counter++;
        }
    }
    cout << counter << endl;
	return 0;
}
