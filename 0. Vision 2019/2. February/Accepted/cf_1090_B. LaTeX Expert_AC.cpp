//http://codeforces.com/contest/1090/problem/B
// somewhat tedious tedious string matching and string manipulation
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
    _INIT;
    int counter,flag,format =0;
    map<string,string> mp;
    string str,temp = "",st;
    vector<string>vec;
    while(1){
        getline(cin, str);
        if(str.substr(0, 7 ) == "\\begin{"){
            st = str;
            break;
        }

        for(int i=0;str[i];i++){
            temp = "";
            //msg(i, str.substr(i,6))
            if(str.substr(i, 6) == "\\cite{"){
                for(int j=i+6;str[j];j++){
                    if(str[j] == '}'){
                        break;
                    }else{
                        temp += str[j];
                    }
                }
            }
            if(temp!= ""){
                vec.push_back(temp);
            }
        }
    }
    string bibiItem = "\\bibitem{";

    //cc(bibiItem.size());
    flag = 1;
    counter = 0;
    while(1){
        getline(cin,str);
        if(str == "\\end{thebibliography}"){
            break;
        }

        temp = "";
        if(str.substr(0, bibiItem.length() ) == bibiItem){
            for(int j=bibiItem.length();str[j];j++){
                if(str[j] == '}'){
                    break;
                }
                temp += str[j];
            }

            mp[temp] = str;
            if(vec[format++] != temp){
                flag = 0;
            }
        }
    }
    if(flag == 0){
        cout << "Incorrect" << endl;
        cout << st << endl;
        for(int i=0;i<vec.size();i++){
            cout << mp[vec[i]] << endl;
        }
        cout << "\\end{thebibliography}" << endl;
    }else{
        cout << "Correct"<<endl;
    }



    return 0;
}
