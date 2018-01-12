#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    double a,b,sum;
    char ch;
    while(1){
        cin >> a >>ch >> b;

        if(a==0 && b ==0){
            break;
        }
        a = a>6? 360 - 30*a : 30*a;
        b = b*5.5;
        sum = a+b;
        if(sum>180){
            cout << fixed<< setprecision(3) <<(sum) - 180 << endl;
        }else{
            cout << fixed<< setprecision(3) << sum<< endl;
        }
    }

	return 0;
}
