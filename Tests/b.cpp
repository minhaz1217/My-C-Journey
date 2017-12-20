//http://codeforces.com/problemset/problem/231/A
#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    int tc, a ,b,c,sum = 0;
    cin >> tc;
    while(tc--){
        cin >> a >> b >> c;
        if(a+b+c >=2){
            sum++;
        }
    }
    cout << sum  << endl;
	return 0;
}
