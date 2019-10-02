/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: http://uva.onlinejudge.org/external/7/719.pdf
Date : 14 / September / 2019
Comment: basic trie problem. updated push.
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define DEBUG 1
#define check(a) DEBUG==1?(cout << a << endl):null;
#define cc(a) DEBUG==1?(cout << a << endl):cout<<"";
#define msg(a,b) DEBUG==1?(cout << a << " : " << b << endl):cout<<"";
#define msg2(a,b,c) DEBUG==1?(cout << a << " : " << b << " : " << c << endl):cout<<"";
#define msg3(a,b,c,d) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << endl):cout<<"";
#define msg4(a,b,c,d,e) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << " : " << e << endl):cout<<"";
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

class nod{
public:
    map<char, nod*>child;
    //nod *child[26];
    int pos, nodMin;
    nod(){
        pos = -1;
        nodMin = 999999;
    }
};
nod *root;
string str;
int sz;
char currMin;
void push(int curr){
    nod *temp = root;
    for(int i=curr;i<curr+sz;i++){
        if(temp->child.find(str[i]) == temp->child.end()){
            temp->child[str[i]]= new nod();
            temp->nodMin = min(temp->nodMin, str[i]-'a');
        }
        if(str[i]-'a' > temp->nodMin){
            return;
        }
        temp = temp->child[ str[i] ];
    }
    temp->pos = curr+1;
}
int main(){
    string temp;
    long long int tc;
    cin >> tc;
    while(tc--){
        cin >> str;
        root = new nod();
        sz = str.size();
        currMin = str[0];
        for(int i=0;i<str.size();i++){
            currMin = min(currMin, str[i]);
        }
        str = str + str;
        //msg("CURRMIN", currMin)
        for(int i=0;i<sz;i++){
            //temp = str.substr(i, sz);
            if(str[i] == currMin){
//                msg("PUSHING", str[i])
                push(i);
            }
        }
        nod *tmp = root;
        while(tmp->pos == -1){
            for(auto it: tmp->child){
                if(it.second!=nullptr){
                    tmp = it.second;
                    break;
                }
            }
            //tmp = tmp->child;
        }
        cout << tmp->pos << endl;
        free(root);
    }
    return 0;
}
