#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    long long counter=0, flag,i,j;
    string str;
    char c;
    getline(cin,str);
    for(i=1;i<=str.length()-2;i++){
        if(str[i] != ',' && str[i] != ' '){
            flag = 1;
            for(j=1;j<i;j++){
                if(str[j] == str[i]){
                    flag = 0;
                    break;
                }
            }
            if(flag ==1){
                counter++;
            }
        }
    }
    cout << counter << endl;

	return 0;
}
