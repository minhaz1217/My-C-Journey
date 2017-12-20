#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int tc,sum1=0,sum2=0,i;
    cin >> tc;
    int arr[tc];
    for(i=0;i<tc;i++){
        cin >> arr[i];
    }
    sort(arr, arr+tc);
    for(i=0;i<tc;i++){
        for(j=i+1;j<tc;j++){
            if(sum1 < 360 - sum1){
                sum1 += arr[j];
            }
        }
    }
    sum2 = 360-sum1;
    cout << abs(sum1-sum2) << endl;
    return 0;
}
