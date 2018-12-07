#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a, b) cout << a << " : " << b << endl;
int main(){
    int tc,a,b,c,d;
    cin >> tc;
    while(tc--){
        cin >> a >> b;
        c = a - (a-b);
        d = a-c;
        if(a < b){
            cout << "impossible" << endl;
        }else{
            cout << (a+b)/2 << " " << -(b-a)/2<< endl;
        }
    }

    return 0;
}
