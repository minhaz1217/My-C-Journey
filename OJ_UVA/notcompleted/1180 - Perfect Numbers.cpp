#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    long long tc, a,flag, i;
    char c;
    cin >> tc;
    cin >> a;
    tc--;
    flag = 1;
    for(i=2;i<=a/2;i++){
        if(a%i == 0){
            flag = 0;
            break;
        }
    }
    if(flag == 1){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    while(tc--){
        cin >> c >> a;
        flag = 1;
        for(i=2;i<=a/2;i++){
            if(a%i == 0){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}
