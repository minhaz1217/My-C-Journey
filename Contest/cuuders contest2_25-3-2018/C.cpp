#include<bits/stdc++.h>
using namespace std;

int main(){
    double n , a, arr[100001] = {0}, m;
    int in = 1;

    cin >> n;
    while(n--){
        cin >> a;
        arr[in] = a;
        sort(arr+1, arr+1+in);
        if(in % 2 == 0){
            m = 1.0*((arr[in/2]+arr[(in/2)+1])/2);
        }
        else{
            m = 1.0*arr[(in+1)/2];
        }
        printf("%0.1f\n",m);
        in++;
    }
    return 0;
}
