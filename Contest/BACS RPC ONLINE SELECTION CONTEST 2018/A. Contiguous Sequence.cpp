#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int tc,n,caseCounter = 1,flag, i;
    cin >> tc;
    while(tc--){
        cin >> n;
        long long int a,prev;
        cin >> a;
        prev = a;
        flag = 0;
        for(i=1;i<n;i++){
            cin >> a;
            if(a == prev+1){
                flag = 1;
            }
            prev = a;
        }
        if(flag == 1){
            cout << "Case " << caseCounter++ << ": Yes" << endl;
        }else{

            cout << "Case " << caseCounter++ << ": No" << endl;
        }
    }
    return 0;
}
