//241959LF
#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define c(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    int personal = 0, named = 0, common = 0, high = 0,none = 0;
    int current=0,tc,i,flag;
    double avg;
    cin >> tc;
    int arr[tc],sum = 0;
    for(i=0;i<tc;i++){
        cin >> arr[i];
        sum += arr[i];
    }

    avg = (double)sum/(double)tc;
   // cout << sum << " : " << avg << endl;
    flag = 1;
    for(i=0;i<tc;i++){
        if(arr[i] != 5){
            flag = 0;
            break;
        }
    }
    if(flag == 1){
        named = 1;
    }
    if(avg >= 4.5){
        high = 1;
    }
    for(i=0;i<tc;i++){
        if(arr[i] == 3){
            none = 1;
            break;
        }
    }
    if(named == 0 && high == 0 && none == 0){
        common = 1;
    }

    if(none){
        cout << "None" << endl;
    }else if(common){
        cout << "Common"<< endl;
    }else if(named == 1){
        cout << "Named" << endl;
    }else if(high){
        cout << "High" << endl;
    }





    return 0;
}
