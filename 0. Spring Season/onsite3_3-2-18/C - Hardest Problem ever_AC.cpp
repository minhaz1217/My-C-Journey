#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a  << " : " << b << endl;
#define msg2(a,b,c) cout << a  << " : " << b  << " : " << c << endl;
int main(){
    int tc,q,i,a,sum;
    cin >> tc;
    while(tc--){
        cin >> q;
        sum = 0;
        for(i=0;i<q;i++){
            cin >> a;
            sum += a;
        }
        //check(sum) ;
        cout << sum-q+1 << endl;
    }


    return 0;
}
