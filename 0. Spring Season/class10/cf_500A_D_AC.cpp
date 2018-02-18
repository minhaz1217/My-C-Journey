#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int n,m,nextPortal, found,i,a;
    cin >> n >> m;
    nextPortal = 1;
    found = 0;
    for(i=1;i<n;i++){
        cin >> a;
        //mat[i].push_back(i+a);
        if(i==nextPortal){
            nextPortal = i + a;
        }
        if(nextPortal == m){
            found = 1;
        }
    }
    if(found == 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }


    return 0;
}
