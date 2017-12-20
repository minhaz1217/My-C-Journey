#include<bits/stdc++.h>
using namespace std;
int main(){
    long long m,n,a;
    cin >> m >> n >> a;
    if(m % a != 0 ){
        m = m/a + 1;
    }else{
        m = m/a;
    }
    if(n %a != 0){
        n = n/a + 1;
    }else{
        n = n/a;
    }
    cout << m*n << endl;


	return 0;
}
