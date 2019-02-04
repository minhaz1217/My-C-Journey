//https://vjudge.net/problem/1991542/origin
// using trie with pointer
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

class nod{
public:
    nod *child[26];
    nod(){
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }

    }
};
nod *root;
int pos;
void push(string s){
    nod *temp = root;
    for(int i=0;s[i];i++){
        if(temp->child[ s[i] -'a' ] == NULL){
            temp->child[ s[i]-'a' ] = new nod();
            if(pos == -1){
                pos = i;
            }
        }else{
        }
        temp = temp->child[ s[i]-'a' ];
    }
}


int main(){
    int tc;
    string str;
    map<string, int>mp;
    root = new nod();
    cin >> tc;
    while(tc--){
        cin >> str;
        if(mp.find(str) == mp.end()){
            mp[str] = 1;
            pos = -1;
            push(str);
            //msg(str, pos)
            if(pos == -1){
                cout << str << endl;
            }else{
                cout << str.substr(0,pos+1) << endl;
            }
        }else{
            mp[str]++;
            cout << str << " " << mp[str] << endl;
        }
    }

    return 0;
}
