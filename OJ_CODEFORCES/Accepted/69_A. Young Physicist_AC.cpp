#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long tc,a,b,c,x=0,y=0,z=0;
    cin >> tc;
    while(tc--){
        cin >> a >> b >> c;
        x += a;
        y +=b;
        z += c;
    }
    if(x ==0 && y ==0 && z==0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
	return 0;
}
