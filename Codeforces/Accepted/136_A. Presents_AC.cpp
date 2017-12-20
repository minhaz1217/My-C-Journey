#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long n,i;
    cin >> n;
    long long arr[n], arr2[n];
    for(i=0;i<n;i++){
        cin >> arr[i];
        arr2[arr[i]-1] = i+1;
    }
    cout << arr2[0];
    for(i=1;i<n;i++){
        cout << " " << arr2[i];
    }
	return 0;
}
