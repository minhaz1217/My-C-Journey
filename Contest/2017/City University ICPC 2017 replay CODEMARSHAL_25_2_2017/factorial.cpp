#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    long long n,i,sum=1,j;
    //cin >> n;
    for(j=1;j<=20;j++){
        sum = 1;
        n = j;
    for(i=1;i<=n;i++){
        sum *= i;
    }
    msg(j, sum)
    }

	return 0;
}

