#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    long long n,m,a,counter = 0,prev;
    cin >> n >>m;
    cin >> a;
    m--;
    counter = a-1;
    prev = a;
    while(m--){
        cin >> a;
        if(a == prev){

        }else if(a > prev){
            counter += a - prev;
        }else if(a < prev){
            counter += (n - prev+1) + (a-1);
        }
        prev = a;
    }
    cout << counter << endl;

	return 0;
}
