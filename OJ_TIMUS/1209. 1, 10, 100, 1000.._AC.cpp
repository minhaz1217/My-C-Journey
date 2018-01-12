#include<bits/stdc++.h>
using namespace std;
int main(){
    long long i,c,a,tc;
    map<int, bool>mp;

    cin >> tc;
    int arr[tc];
    int mm = 0;
    for(i=0;i<tc;i++){
        cin >> arr[i];
        mm = max(arr[i], mm);
    }
    for(i=0;i<=mm;i++){
        c = i*(i+1)/2 + 1;
        if(c>=INT_MAX){
            break;
        }
        mp[c] = 1;
    }
    for(i=0;i<tc;i++){
        if(mp[arr[i]]){
            cout << "1 ";
        }else{
            cout << "0 ";
        }
    }
    cout << endl;
    /*
    cin >> tc;
    while(tc--){
        cin >> a;
    }
    */


    return 0;
}
