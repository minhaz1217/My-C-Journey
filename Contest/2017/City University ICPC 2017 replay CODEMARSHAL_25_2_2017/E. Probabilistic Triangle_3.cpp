#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;



int main(){
    double a,b,c,tc,s,area;
    cin >> tc;
    while(tc--){
        cin >> a >> b >> c;
        a= b-1;
        c= a;
        s = (double)((a+b+c)/2.00);
        area = sqrt(s * (s-a) * (s-b) * (s-c));
        cout << fixed << setprecision(6) << (double)area << endl;
    }

	return 0;
}
