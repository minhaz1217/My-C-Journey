#include<iostream>
using namespace std;
#define msg(a,b) cout << a << " : " << b << endl;
#define check(a) cout << a << endl;

class nod{
public:
    nod *child[10];
    bool wordEnded;
    nod(){
        for(int i=0;i<10;i++){
            child[i]= NULL;
        }
        wordEnded = false;
    }
    ~nod(){
        delete this;
    }
};
int push(nod *root, string s){
    nod *tmp = root;
    for(int i=0;s[i];i++){
        if(tmp->wordEnded == true){
            return 1;
        }
        if(tmp->child[s[i] -'0'] == NULL){
            tmp->child[s[i] - '0'] = new nod();
        }
        tmp = tmp->child[s[i] - '0'];
    }
    tmp->wordEnded = true;
    return 0;
}
int main(){
    int i, tc,n, flag,caseCounter = 1;
    string str;
    cin >> tc;
    while(tc--){
        nod *root;
        root = new nod();
        flag = 0;
        cin >> n;
        while(n--){
            cin >> str;
            if(flag == 0){
                flag = push(root ,str);
            }
        }
        if(flag == 0){
            cout << "Case "<< caseCounter++ << ": YES" << endl;
        }else{
            cout << "Case "<< caseCounter++ << ": NO" << endl;

        }
    }
    return 0;
}
