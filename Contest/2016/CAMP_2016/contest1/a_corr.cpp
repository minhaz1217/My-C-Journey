#include<bits/stdc++.h>
using namespace std;
int main(){
    int tc, n,q,i,caseCounter = 1;
    cin >> tc;
    while(tc--){
        cin >> n;
        cout << "Case " << caseCounter++ << ": " << endl;
        int arr[n],arr1[n],sum=0,a,b;
        for(i=0;i<n;i++){
            cin >> arr[i];
            sum+=arr[i];
            arr1[i]=sum;
        }

        cin >> q;
        for(i=0;i<q;i++){
            cin >> a >> b;
            if(a==1){
                cout<< arr1[b-1]  << endl;
            }
            else{
            cout<< arr1[b-1] - arr1[a-2]  << endl;
            }
        }
    }

    return 0;
}
