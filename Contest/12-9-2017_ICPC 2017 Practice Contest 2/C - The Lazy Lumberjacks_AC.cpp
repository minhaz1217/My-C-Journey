//UVA-11936
#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){

    int tc, arr[3];
    cin >> tc;
    while(tc--){
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr, arr+3);
        if(arr[0] + arr[1] > arr[2]){
            cout <<  "OK" << endl;
        }else{
            cout << "Wrong!!" << endl;
        }

    }



    return 0;
}
