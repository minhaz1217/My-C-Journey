#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    long long int n,k,a,i;
    cin >> n >> k;
    for(i=0;i<n;i++){
        scanf("%d", &a);
        vec.push_back(a);
    }
    sort(vec.begin(), vec.end());
    for(i=k;i<n;i++){
        if(vec[i] == vec[i-1]){
            cout << -1 << endl;
            return 0;
        }
    }
    return 0;
}
