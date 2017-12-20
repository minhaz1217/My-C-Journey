#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    long long tc,i;
    cin >> tc;
    long long arr[tc];
    for(i=0;i<tc;i++){
        cin >> arr[i];
    }
    sort(arr, arr+tc);
    cout << arr[0];
    for(i=1;i<tc;i++){
        cout << " " << arr[i];
    }
	return 0;
}
