#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long i,j,flag,counter = 0;
    string str;
    cin >> str;
    for(i=0;str[i];i++){
        flag = 0;
        for(j=i+1;str[j];j++){
            if(str[j] == str[i]){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            counter++;
        }
    }
    if(counter %2 == 0){
        cout << "CHAT WITH HER!" << endl;
    }else{
        cout << "IGNORE HIM!" << endl;
    }
	return 0;
}
