#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int n,i,flag;
    cin >> n;
    int arr[n];
    for(i=0;i<n;i++){
        cin >> arr[i];
    }
    arr[0] = arr[0] %2;
    for(i=1;i<n-1;i++){
        if(arr[i] == -1){
            flag = 1;
            break;
        }
        flag =0;
        if(arr[i-1] == 1){
            arr[i-1] -= 1;
            arr[i] = arr[i] - 1;
        }
        arr[i] = arr[i] %2;
    }
    if(arr[n-2] == 1 && n-2 >= 0){
        arr[n-2] = 0;
        arr[n-1] -=1;
    }
    arr[n-1] = arr[n-1] %2;
    //msg(arr[n-1], flag)
    for(i=0;i<n;i++){
        //msg(i, arr[i])
        if(arr[i] != 0){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }

    return 0;
}
