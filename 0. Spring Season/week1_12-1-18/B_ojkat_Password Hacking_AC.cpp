#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    double tc,sum,counter;
    string str;
    int i,n;
        cin >> n;
        double arr[n+4];
        for(i=0;i<n;i++){
            cin >> str >> arr[i];
        }

        sort(arr, arr+n);
        sum = 0.000000;
        counter = 1.00;
        for(i=n-1;i>=0;i--){
            sum += (double)(counter++)  * (arr[i]);
        }
        printf("%.4lf\n", sum);

    return 0;
}
