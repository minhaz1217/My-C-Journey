#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    string str;
    cin >> str;
    int i,maxLen =0,flag = 1;
    char current = str[0];

    for(i=0;str[i];i++){
        if(str[i] == current){
            maxLen++;
        }else{
            current = str[i];
            maxLen = 1;
        }

        if(maxLen >=7){
            flag = 0;
            break;
        }
    }
    if(flag == 0){
        cout << "YES";
    }else{
        cout << "NO";
    }



	return 0;
}
