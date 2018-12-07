#include<iostream>
using namespace std;
#define msg(a,b) cout << a << " : " << b << endl;
#define check(a) cout << a << endl;
int currBig = 0;
class nod{
public:
    nod *child[24];
    string prevString;
    int stringPassed;
    nod(){
        for(int i=0;i<24;i++){
            child[i]= NULL;
        }
        prevString = "";
        stringPassed = 0;
    }
    ~nod(){
        delete this;
    }
};
int push(nod *root, string s){
    nod *tmp = root;
    for(int i=0;s[i];i++){
        if(tmp->child[s[i] -'A'] == NULL){
            tmp->child[s[i] - 'A'] = new nod();
        }
        tmp = tmp->child[s[i] - 'A'];
        tmp->prevString = s.substr(0,i);
        tmp->stringPassed++;
        msg(s[i], tmp->prevString )
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
