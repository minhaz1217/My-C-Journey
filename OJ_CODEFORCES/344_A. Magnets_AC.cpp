#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    long long tc,n,prev,counter = 0;
    cin >> tc;
    cin >> n;
    prev = n;
    counter++;
    tc--;
    while(tc--){
        cin >> n;
        if(n != prev){
            counter++;
        }
        prev = n;

    }
    cout << counter << endl;
	return 0;
}
