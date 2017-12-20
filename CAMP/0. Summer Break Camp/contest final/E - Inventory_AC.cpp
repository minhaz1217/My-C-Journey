#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a, b) cout << a << " : " << b << endl;

#define MAX 200000
int main(){
    int arr[MAX] = {0};
    int tc, myCounter = 0,n,i,j,a;
    vector<int>vec;
    cin >> tc;
    n = tc;
    int arr2[tc+5];
    for(j=1;j<=tc;j++){
        cin >> a;
        if(arr[a] == 1){
            // item already listed
            arr2[j] = -1;
            vec.push_back(j);
        }else{
            // item not listed
            arr[a] = 1;
            if(a > n){
                //item not listed but is out of bound
            vec.push_back(j);
            }else{
                // item not listed and not out of bound
                arr2[j] = a;
            }
        }
    }

        for(i=1;i<=n;i++){
            if(arr[i] != 1){
                arr2[vec[myCounter++] ] = i;
            }
        }
        for(i=1;i<=n;i++){
            cout << arr2[i] << " ";
        }
        cout << endl;

    return 0;
}
