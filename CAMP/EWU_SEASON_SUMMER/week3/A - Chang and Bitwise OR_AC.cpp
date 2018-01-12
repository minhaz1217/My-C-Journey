#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int tc,a=0,n,sum=0;



    cin>> tc;
    while(tc--){
        sum = 0;
        cin >> n;
        while(n--){
            cin >> a;
            sum = sum | a;
        }
        cout << sum << endl;
    }

    return 0;
}
