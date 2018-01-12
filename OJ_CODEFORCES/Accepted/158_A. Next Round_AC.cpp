#include<bits/stdc++.h>
using namespace std;
int main(){
    long long i,a, k,n,kNum=0,counter = 0;
    cin >> n >> k;
    long long arr[n+2];
    for(i=1;i<=n;i++){
        cin>> arr[i];
    }
    kNum = arr[k];
    for(i=1;i<=n;i++){
        if(arr[i] >= kNum && arr[i] != 0){
            counter++;
        }
    }


    cout << counter << endl;
	return 0;
}
