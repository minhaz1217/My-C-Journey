#include<iostream>
using namespace std;
class nod{
public:
    nod *child[26];
    nod(){
        for(int i=0;i<26;i++){
            child[i]= NULL;
        }
    }
};
nod *root;
void push(string s){
    nod *tmp = root;
    for(int i=0;s[i];i++){
        if(tmp->child[s[i] -'a'] == NULL){
            tmp->child[s[i] - 'a'] = new nod();
        }
        tmp = tmp->child[s[i] - 'a'];
    }
}
bool qu(string s){
    nod *tmp = root;
    for(int i=0;s[i];i++){
        if(tmp->child[s[i] -'a'] == NULL){
            return false;
        }
        tmp = tmp->child[s[i] - 'a'];
    }
    return true;
}

int main(){
    int i;
    root = new nod();
    string s;
    for(int i=0;i<5;i++){
        cin >> s;
        push(s);
    }

    for(int i=0;i<5;i++){
        cin >> s;
        cout << qu(s) << endl;
    }

    return 0;
}
