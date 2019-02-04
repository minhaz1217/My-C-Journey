//https://vjudge.net/problem/1991542/origin
// using trie with only array, got a WA because the MX was too low(10^5 <- str max size is 10^5) made the array 10^6 and got AC
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define NULLPTR -1
#define MX 1000020

struct Trie{
    int next[26];
    int cnt;
};
int head,pos;
int trieCount;
Trie trie[MX+5];
int createTrie(){
    for(int i=0;i<26;i++){
        trie[ trieCount ].next[i] = NULLPTR;
    }
    trie[trieCount].cnt = 0;
    return trieCount++;
}
void pushInTrie(string str){
    int curr = head;
    int index;
    string temp;
    for(int i=0;str[i];i++){
        index = (str[i]-'a');
        if(trie[curr].next[index] == NULLPTR){
            trie[curr].next[index] = createTrie();
            //msg("PUSHING", str[i])
            if(pos == -1){
                pos = i;
            }
        }
        curr = trie[curr].next[index];
    }
    trie[curr].cnt++;
}

void initTrie(){
    trieCount = 0;
    head = createTrie();
    return;
}

int main(){
    int tc;
    string str;
    map<string, int>mp;
    initTrie();
    cin >> tc;
    while(tc--){
        cin >> str;
        if(mp.find(str) == mp.end()){
            mp[str] = 1;
            pos = -1;
            pushInTrie(str);
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
