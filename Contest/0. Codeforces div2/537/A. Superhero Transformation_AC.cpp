#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int main(){
    int flag1, flag2, flag;
    string vow = "aeiou",str1,str2;
    cin >> str1 >> str2;
    flag = 1;
    for(int i=0;i<min( (int)str1.size() , (int)str2.size());i++){
        flag1 = 0;
        flag2 = 0;
        for(int j=0;vow[j];j++){
            if(str1[i] == vow[j]){
                flag1 = 1;
            }
            if(str2[i] == vow[j]){
                flag2 = 1;
            }
        }
        if(flag1 != flag2){
            flag = 0;
            break;
        }
    }
    if(flag == 1){
        if(str2.size()==str1.size()){
            cout <<"Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }else{
        cout << "No" << endl;
    }

    return 0;
}
