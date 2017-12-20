#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long flag,i,j;
    string str1,str2;
    cin >> str1 >> str2;
    flag = 1;
    if(str1.length() == str2.length()){
        for(i=0,j=str2.length()-1;str1[i];i++,j--){
            if(str1[i]!= str2[j]){
                flag = 0;
            }
        }
    }else{
        flag = 0;
    }
    if(flag == 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
	return 0;
}
