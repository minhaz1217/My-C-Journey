#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a  << " : " << b << endl;
#define msg2(a,b,c) cout << a  << " : " << b  << " : " << c << endl;
int main(){

    int i,a;
    int arr[12];
    for(i=0;i<10;i++){
        cin >> arr[i];
    }
    sort(arr, arr+10);
    cout << arr[9] << endl;
    cout << arr[8] << endl;
    cout << arr[7] << endl;
    return 0;
}
