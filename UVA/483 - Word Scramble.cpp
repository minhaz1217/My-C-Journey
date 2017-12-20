#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    int i;
    string str,s1;
    while(1){
        i = 0;
        getline(cin, str);
        if(cin.eof()){
            break;
        }
        stringstream ss(str);
        while(ss>>s1){
            if(i==-1){
                cout << " ";
            }
            for(i=s1.length() -1;i>=0;i--){
                cout << s1[i];
            }
        }
        cout << endl;
    }
	return 0;
}
