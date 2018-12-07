#include<bits/stdc++.h>
using namespace std;

#define msg(a,b) cout << a << " : " << b << endl;
#define c(a) cout << a <<endl;

int main(){
    int caseCounter = 1;
    long long sum, m,n,i,low,high,mid,tc,flag, temp,prev;
    cin >> tc;
    while(tc--){
        cin >> m >> n;
        int arr[m];
        sum = 0;
        for(i=0;i<m;i++){
            cin >> arr[i];
            sum+= arr[i];
        }
        low = 0;
        high = sum;
        prev = 0;
        //cout << sum << endl;
        while(low< high){
            mid = (high+low)/2;
            if(mid == prev){
                break;
            }
            //cout << mid << endl;
            //cout << high << " : " << low << " : " << mid << endl;
            temp = n;
            sum = 0;
            flag = 1;
            //1 means true, else means false
            for(i=0;i<m;i++){
                if(sum + arr[i] <= mid){
                    sum += arr[i];
                }else{
                    temp--;
                    i--;
                    sum = 0;
                }

                if(temp == 0){
                    //flag = 0;
                    //cout << i << endl;
                    break;
                }
            }
            if(i == m){
               // msg("YES", mid)
                high = mid;
            }else{
               // msg("NO", mid)
                low = mid;
            }
            prev = mid;
        }
        cout << "Case " << caseCounter++ << ": " << high << endl;

    }

    return 0;
}
