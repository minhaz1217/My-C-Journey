/*
Minhazul Hayat Khan
EWU
Problem Name: R - Hyper Prefix Sets
Problem Link: https://vjudge.net/contest/278631#problem/R
Date : 07 / February / 2019
Comment: implemented simple trie data structure and stored a value for the count
*/
//https://vjudge.net/contest/278631#problem/R
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
    int cnt;
    nod *child[26];
    nod(){
        this->cnt = 0;
        for(int i=0;i<26;i++){
            this->child[i] = NULL;
        }
    }
};
nod *head;
int mx;
int conv(char c){
    return c-'0';
}

void push(string str){
    nod *temp = head;
    for(int i=0;str[i];i++){
        if( temp->child[ conv(str[i]) ] == NULL  ){
            temp->child[ conv(str[i]) ] = new nod();
        }

       // msg(conv(str[i]), temp->cnt)
        temp = temp->child[ conv(str[i]) ] ;
        temp->cnt++;
        mx = max(mx, temp->cnt * (i+1));

    }
}

int main(){
    int tc,n,a;

    cin>> tc;
    string str, st;
    a= 0;
    while(tc--){
        cin >> n;
        head = new nod();
        mx = 0;
        while(n--){
            cin >> str;
            push(str);
        }
       cout << mx << endl;
    }
    return 0;
}
