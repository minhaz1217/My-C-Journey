#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int n,i,j;
    string str;
    map<string, string>mp;
    vector<string>vec;
    string colors[7] = {"purple", "green", "blue", "orange", "red", "yellow"};
    string gems[7] = {"Power", "Time", "Space", "Soul", "Reality", "Mind"};
    cin >> n;
    for(i=0;i<n;i++){
        cin >> str;
        for(j=0;j<7;j++){
            if(colors[j] == str){
                colors[j] = "";
                break;
            }
        }
    }
    for(i=0;i<7;i++){
        //cc(colors[i])
        if(colors[i] != ""){
            vec.push_back(gems[i]);
        }
    }

    cout << vec.size() << endl;
    for(i=0;i<vec.size();i++){
        cout << vec[i] << endl;
    }



    return 0;
}
