#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    int i,prev,j;
    string str,s1;
    while(1){
        i = 0;
        getline(cin, str);
        if(cin.eof()){
            break;
        }
        prev = 0;
        for(i=0;str[i];i++){
            if(str[i] == ' ' || i==str.length()-1){
                if(prev !=0 || str[i] == ' '){
                    cout << " ";
                }
                for(j=i; j>=prev;j--){
                    cout << str[j] ;
                }
                prev = i;
            }
        }
        cout << endl;




    }
	return 0;
}
