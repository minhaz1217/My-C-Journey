#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    int i,tc,n, lowestOdd=0, biggestOdd = 0,sum = 0;
    cin >> tc;
    int arr[tc];

    for(i=0;i<tc;i++){
        cin >> arr[i];
        sum += arr[i];
        if(arr[i]%2 != 0 && (lowestOdd == 0 || arr[i] <= lowestOdd)){
            lowestOdd = arr[i];
        }
    }
    if(sum%2 == 0){

        sum -= lowestOdd;
    }
    if(sum%2 == 0){
        cout << 0 << endl;
    }else{
        cout << sum << endl;
    }

	return 0;
}
