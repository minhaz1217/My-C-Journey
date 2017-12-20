#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long int n,sum=0,i;
    for(;;){
        cin >> n;
        if(cin.eof()){
            break;
        }
        sum =0;
        for(i=1;i<=n;i++){
            sum += i*i*i;
        }
        cout << sum << endl;
    }

	return 0;
}
