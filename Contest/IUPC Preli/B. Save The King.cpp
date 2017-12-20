#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long int tc,i,first,num;
    vector<int> arr;
    cin >> tc;
    //long long int arr[tc+1];
    for(i=0;i<tc;i++){
        cin >> num;
        arr.push_back(num);
    }
    first = arr[0];
    sort(arr.begin(), arr.end());
    for(i=0;i<tc;i++){
        cout << arr[i] << endl;
    }
	return 0;
}
