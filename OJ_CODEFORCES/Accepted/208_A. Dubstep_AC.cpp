#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long i,found = 1;
    string str;
    cin >> str;
    for(i=0;str[i];i++){
        if(str[i] == 'W' && str[i+1] == 'U' && str[i+2] == 'B'){
            i+=2;
            if(found == 0){
                cout << ' ';
            }
            found =1;
        }else{
            cout << str[i];
            found = 0;
        }
    }

	return 0;
}
