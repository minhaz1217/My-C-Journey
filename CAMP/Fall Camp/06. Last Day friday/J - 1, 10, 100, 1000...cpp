#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define c(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    long long tc,k,counter,i;
    long long int a;
    double n;
    cin >> tc;
    while(tc--){
        cin >> a;
        n = sqrtf(2.00*(double)a - 1.75) - .5;
        //msg(n,floorf(n))
        if(floorf(n) == ceilf(n) ){
            cout << "1 ";
        }else{
            cout << "0 ";
        }
    }
    cout << endl;
    return 0;
}
