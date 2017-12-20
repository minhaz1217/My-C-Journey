#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long n,m,i,counter = 0;
    cin >> n >> m;
    long long arr[m];
    for(i=0;i<m;i++){
        cin >> arr[i];
    }
    sort(arr, arr+m);
    for(i=0;i+n-1<m;i++){
        arr[i] = arr[i+n-1] - arr[i];
        counter++;
    }
    sort(arr, arr + (m - (n-1)));
    // this ^^ and this >> are both correct
    //sort(arr, arr+counter);
    cout << arr[0] << endl;

	return 0;
}
