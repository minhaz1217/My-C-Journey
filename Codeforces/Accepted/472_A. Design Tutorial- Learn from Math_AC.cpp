#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long n;
    cin >> n;
    if(n%2 ==0){
        cout << 4 << " " << n-4 << endl;
    }else{
        cout << 9 << " " << n-9 << endl;
    }
	return 0;
}
