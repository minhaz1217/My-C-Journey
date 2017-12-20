#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    long long low=0, up=0,i;
    string str;
    cin >> str;
    for(i=0;str[i];i++){
        if(str[i] >= 'a' && str[i] <='z'){
            low++;
        }else{
            up++;
            str[i] = str[i] - 'A' + 'a';
        }

    }
    if(low >= up){
        cout << str << endl;
    }else{
        for(i=0;str[i];i++){
            cout << (char)toupper(str[i]);
        }
    }
	return 0;
}
