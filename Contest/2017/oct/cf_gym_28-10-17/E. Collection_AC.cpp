#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    long long int tc,k,counter= 0;
    map<long long int, bool> mp;
    cin >> tc;
    while(tc--){
        cin >> k;
        if(mp[k]){
            counter++;
        }else{
            mp[k] = 1;
        }
    }
    cout << counter << endl;

    return 0;
}
