#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int i,n,k,counter, temp,flag;

    cin >> n >> k;
    int arr[n];
    flag = 1;
    counter = 0;
    for(i=0;i<n;i++){
        cin >> arr[i];
        if(arr[i] <=k && flag){
            counter++;

        }else{
            flag = 0;
        }
    }
    flag =1;
    temp = counter;
    //cc(counter)
    for(i=n-1;i>=temp;i--){
        //msg(i,arr[i])
        if(arr[i] <= k && flag){
            counter++;
        }else{
            break;
        }
    }
    cout << counter << endl;
    return 0;
}
