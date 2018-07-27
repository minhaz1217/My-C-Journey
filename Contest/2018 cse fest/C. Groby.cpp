#include<bits/stdc++.h>
//#include<iostream>
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a, b) cout <<  a << " : " << b << endl;
#define msg2(a, b, c) cout <<  a << " : " << b << " : " << c << endl;
using namespace std;

int main(){
    double tc;
    int i;
    double arr[4];
    cin >> tc;
    while(tc--){
        cin >> arr[0] >> arr[1];
        //arr[2] = 360.00 - (arr[0]+arr[1]);
        arr[0] = (arr[0]/2);
        arr[1] = (arr[1]/2);
        arr[2] = (180.00- (arr[0]+arr[1]));
        sort(arr, arr+3);
    //cc("HELLO")
        for(i=0;i<3;i++){
            //printf("%.6lf ", arr[i]);
            printf("%lf ", arr[i]);
            //cout << (double)arr[i] << " ";
        }
        printf("\n");
        //cout << endl;
    }
    return 0;
}
