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
    nod *child[52];
    nod(){
        this->cnt = 0;
        for(int i=0;i<52;i++){
            this->child[i] = NULL;
        }
    }
};
nod *root;
long long int sum;

int conv(char myC){
    if(myC >= 'a' && myC<='z'){
        return (myC-'a');
    }else{
        return ((myC-'A') + 26);
    }
}
void push(string str){
    int c;
    nod *temp = root;
    for(int i=0;str[i];i++){
        c = conv(str[i]);
        if(temp->child[ c ] == NULL){
            temp->child[c] = new nod();
        }
        temp = temp->child[c];
    }
    temp->cnt++;
}
void qu(string str){
    int c;
    nod *temp = root;
    for(int i=0;str[i];i++){
        c = conv(str[i]);
        while(temp->child[c] != NULL){
            temp = temp->child[c];
        }
    }
    if(temp->cnt > 0){
        sum = sum * (temp->cnt);
    }
}
int main(){
    _INIT;
    int tc,d,q,caseCounter=1;
    string str,strr;
    cin >> tc;
    while(tc--){
        free(root);
        root = new nod();
        cin >> d;
        sum =1;
        for(int i=0;i<d;i++){
            cin >> str;
            if((int)str.size()>2){
                sort(str.begin()+1, str.end()-1);
            }
            push(str);
        }

        //cc("HELLO")
        cin >> q;
        cout << "Case " << caseCounter++ << ": " << endl;
        cin.ignore();
        //msg("Q", q)
        for(int i=0;i<q;i++){
            getline(cin, strr);
            //cc(strr)
            stringstream ss(strr);
            sum = 1;
            while(ss>>str){
                if((int)str.size()>2){
                    sort(str.begin()+1, str.end()-1);
                }
                qu(str);
            }
            cout << sum << endl;
        }

    }


    return 0;
}
