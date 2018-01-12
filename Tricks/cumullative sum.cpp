#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int n,i,sum;
    cin >> n;
    int arr[n];
    sum = 0;
    for(i=0;i<n;i++){
        cin >> arr[i];
        sum += arr[i];
        arr[i] = sum;
        cout << arr[i] << " ";
    }
    cout << endl;



    return 0;
}
