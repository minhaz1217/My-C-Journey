//codechef KCON
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
int maxSubArraySum(int a[], int sz)
{
    //for(int i=0;i< sz; i++){cout << a[i] << " " << endl;}
    //cout << endl;
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < sz; i++)
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
    cin >> tc;
    while(tc--){
        cin >> n >> k;
        for(i=0;i<n;i++){
            cin >> arr[i];
            if(k==1){

            }else if(k==2){
                arr[i+1*k] = arr[i];
            }else{
                arr[i+1*k] = arr[i];
                arr[i+2*k] = arr[i];
            }
        }
    }

    return 0;
}
