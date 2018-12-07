#include<bits/stdc++.h>
#include<string>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    string str,str2 = "",str3="";
    int i,a,index;
    while(getline(cin,str)){
        if(isdigit(str[0])){
            index = 0;
            str3 = "";
            str2 = "";
            reverse(str.begin(),str.end());
            //cc(str)
            while(1){
                str3 += str[index++];
                if(str3.size() >= 2){
                    stringstream ss(str3);
                    ss >> a;

                    //msg(a, (char)a)
                    if(a<32){
                        a = a*10;
                        a += str[index++] - '0';
                    }
                    str2 += (char)a;
                    str3 = "";
                }

                if(index >= str.size()){
                    break;
                }
            }
        }else{
            str2 = "";
            a = 0;
            for(i=0;str[i];i++){
                a = ((int)str[i]);
                stringstream ss;
                ss << a;
                string s1 = ss.str();
                str2 += s1;
            }
            reverse(str2.begin(), str2.end());
        }
        cout << str2 << endl;
    }

    return 0;
}
