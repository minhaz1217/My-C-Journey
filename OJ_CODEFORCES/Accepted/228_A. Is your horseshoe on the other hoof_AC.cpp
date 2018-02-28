#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    long long int a,b,c,d,counter = 0;
    cin >> a >> b >> c >> d;
    if(a == b || a == c || a ==d){
        counter++;
    }
    if(b == c || b == d){
        counter++;
    }
    if(c == d){
        counter++;
    }
    cout << counter << endl;
	return 0;
}
