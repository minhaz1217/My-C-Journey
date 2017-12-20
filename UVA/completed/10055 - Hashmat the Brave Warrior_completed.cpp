#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long int a, b;
    for(;;){
        cin >> a >> b;
        if(cin.eof()){
            break;
        }
        cout << abs(abs(a) - abs(b) ) << endl;
    }
	return 0;
}
