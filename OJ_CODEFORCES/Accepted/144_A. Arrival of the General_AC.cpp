#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    long long tc,i,n,small, smallPosition, big, bigPosition;
    cin >> tc;
    cin >> n;
    small = n;
    smallPosition = 1;
    big = n;
    bigPosition = 1;
    for(i=2;i<=tc;i++){
        cin >> n;
        if(n <= small){
            small = n;
            smallPosition = i;
        }
        if(n > big){
            big = n;
            bigPosition = i;
        }
    }
    if(bigPosition > smallPosition){
        smallPosition++;
    }
    n = (bigPosition-1) + (tc - smallPosition);
    cout << n << endl;
	return 0;
}
