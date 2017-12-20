#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
        long long m,n,big,small;
        cin >> m>>n;
        big = max(m,n);
        small = min (m,n);
        cout << floor((m*n)/2);
	return 0;
}
