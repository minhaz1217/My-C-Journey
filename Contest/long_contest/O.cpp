#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    int a;
    long long int ans;
    cin >> a;
    if(a==2){
        cout << 2 << endl;
    }else if(a==1){
        cout << 1 << endl;
    }else{
            ans = a * (a-1) * (a-2);
        cout << a * (a-1) * (a-2) << endl;
    }

        return 0;
}
