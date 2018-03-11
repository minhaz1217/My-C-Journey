#include<bits/stdc++.h>
using namespace std;
int main(){

    long long q,flag = 1,caseCounter = 1,i,a,b;
    string str;
    char curr;
    while(1){
        cin >> str;
        if(str[0]!= '0' && str[0] != '1'){
           break;
        }
        cin >> q;
        cout << str << endl;
        if(cin.eof()){
            break;
        }
        cout << "Case " << caseCounter++ << ":" << endl;
        while(q--){
            cin >> a >> b;
            flag = 1;
            for(i=a;i<=b;i++){
                if(str[a] != str[i]){
                    flag = 0;
                    break;
                }
            }
            if(flag == 1){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
	return 0;
}
