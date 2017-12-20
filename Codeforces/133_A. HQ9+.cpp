#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    string str;
    int flag = 0,i;
    cin >> str;
    for(i=0;str[i];i++){
        if(str[i] == 'H' || str[i] == 'Q' || str[i] == '9'){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        cout << "YES";
    }else{
        cout << "NO";
    }

	return 0;
}
