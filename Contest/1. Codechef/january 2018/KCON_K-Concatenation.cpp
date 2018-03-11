// -1 -2 1
#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
int maxSubArraySum(int a[], int size)
{
    //for(int i=0;i< size; i++){cout << a[i] << " " << endl;}
    //cout << endl;
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
int main(){
    long long i,tc,n,k,sum,a,firstNegative, lastNegative;
    int foundFirstPositive;
    cin >> tc;
    while(tc--){
        cin >> n >> k;
        int arr[3*n+4];
        sum = 0;
        firstNegative = 0;
        lastNegative = 0;
        foundFirstPositive = 1;
        for(i=0;i<   n;i++){
            cin >> arr[i];
            if(arr[i] <= 0 && foundFirstPositive){
                firstNegative+= arr[i];
            }else if(arr[i]<= 0){
                lastNegative += arr[i];
            }else{
                foundFirstPositive = 0;
                lastNegative = 0;
            }
            if(k == 1){
                sum += arr[i];

            }else if(k == 2){
                arr[i+n] = arr[i];
            }else{
                arr[i+n] = arr[i];
                arr[i+2*n] = arr[i];
            }
            sum += arr[i];
        }
        /*
        for(i=0;i<3*n;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        */
        msg(firstNegative, lastNegative)
        if(k == 1){
            a = maxSubArraySum(arr, n);
        }else if(k == 2){
            a = maxSubArraySum(arr, 2*n);
        }else{
            a = maxSubArraySum(arr, 3*n);
        }
        cout << a << " " << sum << " " << k* sum<< endl;
        //msg(a, sum)
        cout << max(max(k*sum, max(k*sum - firstNegative, max(k*sum - lastNegative, k*sum - (firstNegative + lastNegative)))),a) << endl;
    }


    return 0;
}
