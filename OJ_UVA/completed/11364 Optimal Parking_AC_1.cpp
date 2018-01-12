#include<bits/stdc++.h>
using namespace std;
int main(){
    long long tc,p,i, sum =0;
    cin >> tc;
    while(tc--){
        cin >> p;
        long long arr[p];
        for(i=0;i<p;i++){
            cin >> arr[i];
        }
        sort(arr, arr + p);
        sum = arr[p-1] - arr[0];
        for(i=p-1;i>0;i--){
            sum += arr[i] - arr[i-1];
        }
        cout << sum << endl;
    }


	return 0;
}
