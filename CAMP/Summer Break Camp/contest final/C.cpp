#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a, b) cout << a << " : " << b << endl;
int main(){
    int n,m, a,b,flag= 1,i;
    cin >> n>> m;
    int arr[m+1];
    for(i=1;i<= m;i++){
        arr[i] = 0;
    }
    while(n--){
        cin >> a;
        while(a--){
            cin >> b;
            arr[b] = 1;
        }
    }
    flag =1;
    for(i=1;i<= m;i++){
        if(arr[i] == 0){
            flag = 0;
            break;
        }
    }
    if(flag == 0){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
    return 0;
}
