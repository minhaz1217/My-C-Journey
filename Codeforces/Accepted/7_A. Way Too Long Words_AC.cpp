#include<bits/stdc++.h>
using namespace std;
int main(){
    long long tc;
    string str;
    cin >> tc;
    while(tc--){
        cin >> str;
        if(str.length() > 10){
            cout << str[0] << str.length() -2 << str[str.length()-1] << endl;
        }else{
            cout << str << endl;
        }
    }
	return 0;
}
