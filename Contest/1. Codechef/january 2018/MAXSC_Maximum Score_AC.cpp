#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){

    long long tc, i,j,n, curr, sum, counter;
    cin >> tc;
    while(tc--){
        cin >> n;
        long long arr[n+4][n+4];
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cin >> arr[i][j];
            }
            sort(arr[i], arr[i]+n);
        }
        curr = arr[n-1][n-1];
        sum = curr;
        counter = 1;
        for(j=n-2;j>=0;j--){
            for(i=n-1;i>=0;i--){
                if(arr[j][i] < curr){
                    curr = arr[j][i];
                    sum += curr;
                    //msg(curr, sum)
                    counter++;
                    break;
                }
            }
        }
        if(counter == n){
            cout << sum << endl;
        }else{
            cout << -1 << endl;
        }
    }



    return 0;
}
