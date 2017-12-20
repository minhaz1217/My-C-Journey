#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    string str;
    int tc,sum = 0;
    cin >> tc;
    while(tc--){
        cin >> str;
        if(str[0] == '+' || str[str.length()-1] == '+'){
            sum++;
        }else if(str[0] == '-' || str[str.length()-1] == '-'){
            sum--;
        }
    }
    cout << sum;



	return 0;
}
