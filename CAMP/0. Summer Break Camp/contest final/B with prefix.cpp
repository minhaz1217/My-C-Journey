#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a, b) cout << a << " : " << b << endl;
class nod{
public:
    nod *child[26];
    bool isPrefix;
    nod(){
        for(int i=0;i<26;i++){
            child[i] = NULL;
            isPrefix = false;
        }
    }
};
nod *root;


bool checkPalin(string str){
    int i,j;
        for(i=0, j= str.length()-1;str[i];i++,j--){
            if(str[i] != str[j]){
                return false;
                break;
            }
        }
        return true;
}

void push(string s){
    nod *tmp = root;
    for(int i=0; s[i];i++){
        if(tmp->child[ s[i] -'a' ] = NULL){
            tmp->child[ s[i] - 'a' ] = new nod();

        }
        tmp = tmp->child[ s[i] - 'a' ];
    }
}

int main(){


    return 0;
}
