#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long tc,num;
    string str;
    cin >> tc;
    while(tc--){
        cin >> str;
        if(str.length() <=2){
            cout << "+" << endl;
        }else{
            if(str[0] == '9'){
                cout << "*" << endl;
            }else if(str[1] == '9'){
                cout << "?" << endl;

            }else{
                cout << "-" << endl;
            }
        }
    }
	return 0;
}
