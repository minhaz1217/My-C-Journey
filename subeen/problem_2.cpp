#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long tc,a, even =0, odd=0;
    cin >> tc;
    while(tc--){
        cin >> a;
        if(a>=0){
            even++;
        }else{
            odd++;
        }
    }
    cout << even << " " << odd << endl;

	return 0;
}
