#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    int tc,i;
    cin >> tc;
    int arr[tc];
    for(i=0;i<tc;i++){
        cin >> arr[i];
    }
    sort(arr, arr+tc);
    for(i=0;i<tc;i++){
        cout << arr[i] << " ";
    }
	return 0;
}
