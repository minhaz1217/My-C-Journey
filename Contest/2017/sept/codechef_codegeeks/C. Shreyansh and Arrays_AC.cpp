#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int tc,a,b,i,j,flag = 0;
    cin >> tc;
    while(tc--){
        cin >> a >> b;
        int arr[a];
        for(i=0;i<a;i++){
            cin >> arr[i];
        }
        flag = 0;
        for(i=0;i<a && !flag;i++){
            for(j=i+1;j<a;j++){
                if(arr[i] + arr[j] == b && arr[i] != arr[j]){
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 1){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }


    }

    return 0;
}
