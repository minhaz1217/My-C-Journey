#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long arr[4],d,i,flag =1,counter =0,j;
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> d;

    sort(arr,arr+4);
    if(arr[0] == 1 || arr[1] == 1 || arr[2] == 1|| arr[3] == 1){
        cout << d << endl;
        return 0;
    }
    for(i=1;i<=d;i++){
        flag = 1;
        for(j=0;j<4;j++){
            if(i%arr[j] == 0){
                flag =0;
                break;
            }
        }
        if(flag == 1){
            counter++;
        }
    }
    cout << d-counter << endl;


	return 0;
}
