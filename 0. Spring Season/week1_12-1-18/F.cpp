#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int tc, n , sum,i;
    cin>> tc;
    while(tc--){
        cin >> n;
        sum = 0;
        long long arr[n], pos[n];
        for(i=0;i<n;i++){
            cin >> arr[i];
            pos[i] = arr[i];
        }
        sort(arr, arr+n);
        int p = lower_bound(pos, pos+n, arr[n-1])- pos;

        if((n-1) - p > 0){
            sum += n-1 -p;
            msg(p, sum)
        }
        for(i=n-2;i>=0;i--){
            p = (lower_bound(pos, pos+n, arr[i])) - pos;
            if( (i+1) - p>0){
                sum += (i) - (p+1);
            }
        }
        cout << sum << endl;


    }

    return 0;
}
