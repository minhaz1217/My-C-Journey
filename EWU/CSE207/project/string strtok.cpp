#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int i;
    char tokens[] = " ;,.+-*/=<>-&|{}[]()";
    string testStr = "cout << \"HI HI HI\" << endl;";
    char c[222], d[2222];
    for(i=0;splitKeys[i];i++){
        c[i] = splitKeys[i];
    }
    c[i] = '\0';
    for(i=0;testStr[i];i++){
        d[i] = testStr[i];
    }
    d[i] = '\0';
    char *p;
    p = strtok(d, c);
    while(p!=NULL){
        check(p);
        p = strtok(NULL, c);
    }

    return 0;
}
