#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    string str;
    while(cin >> str){
            long long int upper=0, lower=0, sz = str.size(),type1=0,type2=0, change = 0;
        for(int i=0;i<sz;i++){
            if(i%2 == 0){
                if(isupper(str[i])){
                    type1++;
                }else{
                    type2++;
                }
            }else{
                if(islower(str[i])){
                    type1++;
                }else{
                    type2++;
                }

            }
        }
        //cc(change)
        //msg(type1, type2)
        cout << min(type1,type2) << endl;
    }
    return 0;
}
