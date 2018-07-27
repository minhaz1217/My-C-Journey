#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int n,k,i,myI;
    string str;

    cin >> n >> k >> str;
    int arr[27];
    for(i=0;i<27;i++){
        arr[i] = 0;
    }
    for(i=0;str[i];i++){
        arr[ str[i]-'a' ]++;
    }
    //for(i=0;i<27;i++)msg(i,arr[i])
    for(i=0;i<27;i++){
        k = k-arr[i];
        if(k <0 ){
            k = k+arr[i];
            break;
        }else if(k==0){
            break;
        }
        arr[i] = -1;
    }
    if(k == 0){
        arr[i] = -1;
        i++;
    }
    myI = i;

    //k--;
    //msg(k, myI)
    for(i=0;str[i];i++){
        if(arr[str[i]-'a'] != -1){
            if(str[i] - 'a' == myI && k != 0){
               // cout <<str[i];
                k--;
            }else{
                cout << str[i];
            }
        }
    }
    cout << endl;


    return 0;
}
