#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    long long n,i,j,len,flag,maxLen=0,currLen;
    string str,str2,str3,chStr;
    while(1){
        cin >> n >> str;
        if(cin.eof()){
            break;
        }
        len = str.length();
        maxLen = 0;

        for(i=0;i<=len-n;i++){
            str2 = str.substr(i,n);
            currLen = 0;
            for(j=i+1;j<=len-n;j++){
                str3 = str.substr(j,n);
                if(str2 == str3){
                    currLen++;
                }
            }
            if(maxLen < currLen){
                maxLen = currLen;
                chStr = str2;
            }
        }
        cout << chStr<<endl;
    }
	return 0;
}
