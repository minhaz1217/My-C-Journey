#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){

    int tc,p,k,l,a,i,counter, multi, sum;

    cin >> tc;
    while(tc--){
        cin >> p >> k >> l;
        int arr[l+1];
        for(i=0;i<l;i++){
            cin >> a;
            arr[i] = a;
        }
        sort(arr, arr+l);
        counter = 0;
        multi = 1;
        sum = 0;
        for(i=l-1;i>=0;i--){
            if(counter == k){
                counter = 0;
                multi++;
            }

            counter++;
            sum = sum + (arr[i] * multi);
            //check(sum)
        }
        cout << sum << endl;
    }

    return 0;
}
