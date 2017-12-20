#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    int tc,a,b,c,sum = 0,counter =0;
    cin >> tc;
    while(tc--){
        cin >> a >> b >> c;
        sum = a+b+c;
        if(sum >= 2){
            counter++;
        }
    }
    cout << counter;

	return 0;
}
