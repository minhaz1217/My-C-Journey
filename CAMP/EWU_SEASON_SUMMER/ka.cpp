#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,q,qt,x,y,la=0,in,temp,j;

    cin >> n >> q;
    int arr[n][q]={0},i[n]={0};
    for(j=0;j<n;j++){
        i[j] = 0;
    }
    while(q--){
       cin >> qt >> x >> y;
       if(qt==1){
            in=(x^la)%n;
            arr[in][ i[in]++ ] =y;
       }
       else{
        in=(x^la)%n;
        la=arr[in][ y%i[in] ];
        cout << la << endl;
       }
    }


    return 0;
}
