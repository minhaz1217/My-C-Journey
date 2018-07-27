#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int i,j,n,flag,currMax = 0;
    string str;
    cin >>  n >> str;
    n = str.size();
    for(i=0;i<n;i++){
        flag = 1;
        for(j=0;j<=i;j++){
            if(str[j] != str[i+j+1]){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            currMax = max(currMax, i);
        }
    }
    if(currMax == 0){
        cout << n << endl;
    }else{
        cout << n- (currMax+1)+1 << endl;
    }

    return 0;
}
