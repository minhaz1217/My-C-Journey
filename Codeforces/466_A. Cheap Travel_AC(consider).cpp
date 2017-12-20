#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    long long  n,m,a,b,price = 0;
    cin >> n >> m >> a >>b;
    while(n>0){


        if(m*a > b && n>=m ){
            price += b;
            n -=m;
        }else if(n == 1 && a <=b){
            price+=a;
            n--;
        }else if(a*n >= ceil((double)n/(double)m)*b){
            price += b;
            n -=m;
        }else{
            price += a;
            n--;
        }
    }
    cout << price << endl;

	return 0;
}
