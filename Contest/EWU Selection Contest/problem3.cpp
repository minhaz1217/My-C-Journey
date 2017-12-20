#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    if(m/b <= a){
        cout << ((n/m)*b) + (n%m)*a << endl;

    }else{
        cout << n*a << endl;
    }

	return 0;
}
