#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int i,sum=0,flag = 1;
    int arr[6];

    for(i=0;i<6;i++){
        cin >> arr[i];
    }
    sum =0;
    while(flag){
        for(i=0;i<6;i++){
            if(arr[i] == 0){
                flag = 0;
                break;
            }
        }
        for(i=0;i<6 && flag;i++){
            sum += (arr[i] + arr[i]-1);
            //msg(arr[i], sum)
            arr[i]--;
        }
    }
    for(i=0;i<6;i++){
        if(arr[i] != 0){
            sum+=1;
            break;
        }
    }
    cout << sum << endl;
    return 0;
}
