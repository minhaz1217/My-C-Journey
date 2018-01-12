#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    int tc,a;
    cin >> tc;
    while(tc--){
        cin >> a;
        if(a >= 10){
            cout << 10 << " " << a-10 << endl;
        }else{
            cout << 0 << " " << a << endl;
        }
    }
	return 0;
}
