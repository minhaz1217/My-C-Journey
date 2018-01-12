#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    int i,firstDQ = 1, firstSQ = 1;
    string str;
    while(1){
        getline(cin, str);
        if(cin.eof()){
            break;
        }
        for(i=0;str[i];i++){
            if(str[i] == '"'){
                if(firstDQ == 1){
                    cout << "``";
                    firstDQ = 0;
                }else{
                    cout << "''";
                    firstDQ = 1;
                }
            }else if(str[i] == '\''){
                if(firstSQ == 1){
                    cout << "`";
                    firstSQ = 0;
                }else{
                    cout << "'";
                    firstSQ = 1;
                }
            }else{
                cout << str[i];
            }
        }
        cout << endl;
    }


	return 0;
}
