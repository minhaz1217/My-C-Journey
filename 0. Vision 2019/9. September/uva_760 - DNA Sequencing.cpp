/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 21 / September / 2019
Comment: consider for all lowercase alphabet and also unique order, such as ab ab should only output ab once.

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

class node{
    public:
    node *next[130];
    node(){
        for(int i=0;i<130;i++){
            next[i] = NULL;
        }
    }
};
node *head;
int conv(char c){
    return (int)(c);
//    if(c >='a' && c<='z'){
//        return c-'a';
//    }else{
//        return c-'A' + 26;
//    }
}
string str;
void insert(int pos){
    node *curr = head;
    for(int i=pos;i<str.size();i++){
        if( curr->next[ conv(str[i]) ] == NULL ){
            curr->next[ conv(str[i]) ] = new node();
//            msg("PUSHED", str[i])
        }
        curr = curr->next[ conv(str[i]) ];
    }
}
string searchTree(string s){
//    cc(s)
    string temp = "";
    node *curr = head;
    for(int i=0;i<s.size();i++){
        if(curr->next[ conv(s[i]) ] != NULL){
            curr = curr->next[ conv(s[i]) ];
            temp.push_back(s[i]);
        }else{
//            msg("RET", temp)
            return temp;
        }
    }
}
int main(){
    string str1,str2,temp,sen;
    int currMax,caseCounter = 1;

    while(getline(cin, str1)){
        if(str1.size()<1){
            break;
        }
        getline(cin , str2);
        vector<string>vec;
        set<string>mainVec;
        head = new node();
        str = str1;
        for(int i=0;i<str1.size();i++){
            insert(i);
        }
        currMax = INT_MIN;
        for(int i=0;i<str2.size();i++){
            sen = str2.substr(i);
//            msg("SENT", sen)
            temp = searchTree( sen );
//            cout << temp << endl;
            currMax = max(currMax, (int)temp.size());
            if(temp.size() >= currMax){
                vec.push_back(temp);
            }
            //i+= temp.size()-1;
        }
        for(int i =0;i<vec.size();i++){
            if((int)vec[i].size() == currMax){
                mainVec.insert(vec[i]);
            }
        }
        if(caseCounter++>1){
            cout << endl;
        }

//        sort(mainVec.begin(), mainVec.end());
        if(mainVec.size()>=1){
            for(auto it: mainVec){
                cout << it << endl;
            }
        }else{
            cout << "No common sequence." << endl;
        }
//        cc("END")

    }
    return 0;
}
