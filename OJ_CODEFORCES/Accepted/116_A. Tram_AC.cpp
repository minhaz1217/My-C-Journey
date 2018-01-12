#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long tc,out,in,train=0,big=0;
    cin >> tc;
    while(tc--){
        cin >> out >> in;
        train -= out;
        train += in;
        if(train > big){
            big = train;
        }
    }
    cout << big << endl;



	return 0;
}
