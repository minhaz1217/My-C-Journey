#include<iostream>
using namespace std;
#define msg(a,b) cout << a << " : " << b << endl;
#define check(a) cout << a << endl;
int currBig = 0;
char minChar[32] = {1}, maxChar[32] = {0}
class nod{
public:
    nod *child[2];
    nod(){
        for(int i=0;i<2;i++){
            child[i]= NULL;
        }
    }
    ~nod(){
        delete this;
    }
};
int push(nod *root, string s){
    nod *tmp = root;
    for(int i=0;s[i];i++){
        if(tmp->child[s[i] -'0'] == NULL){
            tmp->child[s[i] - '0'] = new nod();
        }
        if(s[i] == '1'){
            if(tmp->child[0] != NULL){
                maxChar[i] = '0';
            }else{
                maxChar[i] = '1';
            }
            if(tmp->child[1] != NULL){
                minChar[i] = '1';
            }else{
                minChar[i] = '0';
            }
        }
        if(s[i] == '0'){
            if(tmp->child[1] != NULL){
                maxChar[i] = '1';
            }else{
                maxChar[i] = '0';
            }
            if(tmp->child[0] != NULL){
                minChar[i] = '0';

            }else{
                minChar[i] = '1';
            }
        }

        tmp = tmp->child[s[i] - '0'];
    }
    return 0;
}
int main(){
    int i, tc,n, flag,caseCounter = 1;
    string str;
    cin >> tc;
    nod *root;
    currBig = 0;
    while(tc--){
        cin >> n;
        root = new nod();
        while(n--){
            cin >> str;
            push(root, str );
        }
        cout << currBig << endl;

    }
    return 0;
}
