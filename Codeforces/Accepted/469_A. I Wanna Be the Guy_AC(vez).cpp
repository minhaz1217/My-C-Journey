#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    long long tc,i,n,flag,p,q;
    cin >> tc;
    long long arr[tc+1];
    for(i=0;i<=tc;i++){
        arr[i] = 0;
    }
    cin >> p;
    while(p--){
        cin >> n;
        arr[n] =1;
    }
    cin >> q;
    while(q--){
        cin >> n;
        arr[n] =1;
    }
    flag = 1;
    for(i=1;i<=tc;i++){
        if(arr[i] == 0){
            flag = 0;
            break;
        }
    }
    if(flag == 1){
        cout << "I become the guy." << endl;
    }else{
        cout << "Oh, my keyboard!" << endl;
    }



	return 0;
}
