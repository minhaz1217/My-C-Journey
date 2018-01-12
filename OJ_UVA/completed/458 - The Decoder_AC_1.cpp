#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    long long i;
    string str;
    for(;;){
        cin >> str;
        if(cin.eof()){
            break;
        }
        for(i=0;str[i];i++){
            cout << (char)(str[i] - 7);
        }
        cout << endl;

    }
	return 0;
}
