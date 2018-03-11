#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    long long tc,n,i;
    cin >> tc;
    while(tc--){
        cin >> n;
        if(n<=3){
        for(i=1;i<=n;i++){
            cout  << i << " ";
        }
        cout << endl;
    }else{
        cout << -1 << endl;
    }
    }

    return 0;
}
