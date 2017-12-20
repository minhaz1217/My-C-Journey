#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a,b,i,sum=0;
    cin >> n >> m >> a >> b;
    if(a*m <= b){
        //a is less
        cout << n*a << endl;
    }else if(n%m == 0){
        cout << (n/m)*b << endl;
    }else{
        for(i=1;;i++){
            if(m*i > n){
                break;
            }
        }
        i-=1;
        cout << b*i + (n -(m*i) )*a << endl;
    }
	return 0;
}
