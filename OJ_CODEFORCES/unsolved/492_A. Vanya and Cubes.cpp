#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    long long n,sum=0,i=1;
    cin >>n;
    for(i=1;;i++){
        sum += i*(i+1)/2;
        if(n<sum){
            break;
        }
    }
    cout << i-1 << endl;

	return 0;
}
