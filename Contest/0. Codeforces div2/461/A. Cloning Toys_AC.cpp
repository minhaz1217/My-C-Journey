#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    long long int c,o;
    cin >> c >> o;

    if(o==1 && c >0){
        cout << "NO" << endl;
    }else if((o >= c && o-c > 1) || o < 1){
        cout << "NO" << endl;
    }else if( (c%2 == 0 && o%2==0) || (c%2 !=0 && o%2 !=0)){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }


    return 0;
}
