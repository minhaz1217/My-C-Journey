#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long tc,i,sum=0,mySum =0, counter = 0;
    cin >> tc;
    long long arr[tc];
    for(i=0;i<tc;i++){
        cin >> arr[i];
        sum+= arr[i];
    }
    sort(arr,arr+tc);
    for(i=tc-1;i>=0;i--){
        mySum += arr[i];
        counter++;
        if(mySum > (sum - mySum)){
            //cout << sum << endl << mySum << endl;
            break;
        }
    }
    cout << counter << endl;
	return 0;
}
