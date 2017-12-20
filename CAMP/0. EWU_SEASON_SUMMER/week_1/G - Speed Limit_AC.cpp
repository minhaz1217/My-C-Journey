#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int tc,m,t,p,sum;
    while(1){
        cin >> tc;
        if(tc==-1){
            break;
        }
        sum =0;
        p =0;
        while(tc--){
            cin >> m >> t;
            sum += (m * (t-p));
            p = t;
        }
        cout << sum  << " miles"<< endl;

    }
    return 0;
}
