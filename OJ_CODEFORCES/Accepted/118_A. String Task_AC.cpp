#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    string str,alf= "AEIOUYaeiouy";
    int i,j,flag = 0;
    cin >> str;
    for(i=0;str[i];i++){
        for(j=0;alf[j];j++){
            flag =0;
            if(str[i]  == alf[j]){
                flag = 1;
                break;
            }
        }
            if(flag == 0){
                cout<<"."<<(char)tolower(str[i]);
            }
    }
	return 0;
}
