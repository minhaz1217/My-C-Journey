#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int n,i,temp;
    string str;
    cin >> n;
    cin >> str;
    int arr[60];
    for(i=0;i<60;i++){
        arr[i] = 0;
    }
    for(i=0;str[i];i++){
        temp = str[i];
        if(temp >= 'a' && temp <= 'z'){
            arr[temp-'a'+1]++;
        }else{
            arr[temp - 'A'+27]++;
        }
    }
    oneCounter = 0;
    for(i=1;i<60;i++){
        if(arr[i] == 1){
            oneCounter++;
        }
    }
    if(oneCounter == n){
        cout << n << endl;
    }
    return 0;
}
