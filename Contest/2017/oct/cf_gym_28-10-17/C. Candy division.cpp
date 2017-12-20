#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    long long int tc;
    unsigned long long int k;
    cin >> tc;
    while(tc--){
        cin >> k;
        if(k%3 == 0){
            cout << k/3 << " " << k/3 << " " << k/3 << endl;
        }else if(k == 4){
            cout << "2 1 1" << endl;
        }else{
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}
