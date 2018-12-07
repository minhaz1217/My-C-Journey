#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    string str, str3;
    int i,left;
    while(1){
        getline(cin, str);
        if(str == "DONE"){
            break;
        }
        char str2[2000];
        left = 0;
        for(i=0;str[i];i++){
            //cc(str[i])
            if( ( str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <='Z')){
                str2[left++] = tolower(str[i]);
            }
        }
        str2[left] = '\0';
        str3 = str2;
        //cc(str2)
        reverse(str3.begin(), str3.end());
        if(str2 == str3){
            cout << "You won't be eaten!" << endl;
        }else{
            cout << "Uh oh.." << endl;
        }


    }
    return 0;
}
