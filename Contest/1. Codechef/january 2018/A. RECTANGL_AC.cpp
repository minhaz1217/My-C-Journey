#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int tc,i;
    cin >> tc;
    int arr[4];
    while(tc--){
        for(i=0;i<4;i++){
            cin >> arr[i];
        }
        sort(arr, arr+4);
        if(arr[0] == arr[1] && arr[2] == arr[3] ){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}
