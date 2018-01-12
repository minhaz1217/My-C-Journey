#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    long long s,n,x,y,flag = 1,i,j;
    cin >> s >> n;
    long long arr[n][2];
    for(i=0;i<n;i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[i][0] > arr[j][0]){
                x = arr[i][0];
                arr[i][0] = arr[j][0];
                arr[j][0] = x;
                x = arr[i][1];
                arr[i][1] = arr[j][1];
                arr[j][1] = x;
            }
        }
    }
    for(i=0;i<n;i++){
        if(s > arr[i][0] && flag){
            s+= arr[i][1];
        }else{
            flag = 0;
            break;
        }
    }
    if(flag){
        cout << "YES"<< endl;
    }else{
        cout << "NO" << endl;
    }


	return 0;
}
