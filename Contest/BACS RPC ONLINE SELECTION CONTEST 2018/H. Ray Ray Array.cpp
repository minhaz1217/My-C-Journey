#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

#define MX 100004
long long int arr[MX];

int main(){
    long long int tc;
    cin >> tc;
    while(tc--){
        long long int n,q,t,x,y,i,j;
        cin >> n >> q;
        for(i=1;i<=n;i++){
            cin >> arr[i];
        }
        //msg(n,q)
        for(j=0;j<q;j++){
            cin >> t >> x >> y;
            if(t == 1){
                for(i=1;i<=n;i++){
                    if(arr[i] <= x){
                        arr[i] -= y;
                    }
                }
            }else{
                for(i=1;i<=n;i++){
                    if(arr[i] >= x){
                        arr[i] += y;
                    }
                }
            }
        }
        cout << arr[1];
        for(i=2;i<=n;i++){
            cout << " " << arr[i];
        }
        cout << endl;
    }
    return 0;
}
