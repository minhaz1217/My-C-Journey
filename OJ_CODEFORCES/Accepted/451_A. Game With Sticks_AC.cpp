#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long a,b,small;
    cin >> a >> b;
    small = a<=b ? a : b;
    if(small %2 == 0 && small != 1){
        cout << "Malvika" << endl;
    }else{
        cout << "Akshat" << endl;
    }
	return 0;
}
