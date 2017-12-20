#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    string st = "if()";
    cout << st[st.find("if") + 2 ]<< endl;

    return 0;
}
